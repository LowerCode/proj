#pragma once
/*
@author zhp
@date 2017/2/5 22:35
@purpose for game class
*/
#include <string>
#include <Protocol/P_Defines.h>
#include <queue>
#include <Common/UsefulClass.h>
#include <Net/IoTimer.h>
#include "GType.h"
#include <unordered_map>
#include <WgFacility/CmnSceneHandler.h>

namespace GClass{
	struct stBasePro{
		stBasePro() :level_(0), power_(0), smart_(0), brain_(0){}
		bool operator >= (const stBasePro& rhs) const{
			return level_ >= rhs.level_ && power_ >= rhs.power_ && smart_ >= rhs.smart_ && brain_ >= rhs.brain_;
		}
		bool operator < (const stBasePro& rhs) const{
			return !(*this >= rhs);
		}
		pt_dword				level_;			//等级
		pt_dword				power_;			//力量
		pt_dword				smart_;			//敏捷
		pt_dword				brain_;			//智力
	};
	struct stFlaskSpeed{
		int index_;
		int speed_;
	};
	struct stLessSpeed{
		inline bool operator()(const stFlaskSpeed& left, const stFlaskSpeed& right){
			return left.speed_ < right.speed_;
		}
	};
	typedef std::multiset<stFlaskSpeed, stLessSpeed> FlaskSpeedInfo;
	typedef std::vector<int>	GemLinkConT;
	
	struct stGemInfo
	{
		enCD_GemSlotColor  gem_color_;
		std::string		   gem_name_;
		bool			   gem_main_;
	};
	struct stSlotInfo
	{
		stSlotInfo() :is_use_(false), index_(0), color_(kGSC_Invalid){}
		enCD_GemSlotColor color_;
		int  index_;
		bool is_use_;
	};
	struct stGemSoltInfo
	{
		int							link_value_;
		enCD_InventoryType			dst_inventory_;
		std::vector<stSlotInfo>		solt_color_;
	};
	typedef std::vector<stGemSoltInfo> VcSlotInfoConT;
	struct stEmboitementInfo
	{
		stEmboitementInfo() :item_type(kITYPE_Invalid), item_color_(kIC_Non),cnt_(0){}
		enCD_ItemType	item_type;
		enCD_ItemColor  item_color_;
		int				cnt_;
	};
	typedef std::vector<stEmboitementInfo>  LackConT;
}
typedef std::map<enCD_FlaskType, GClass::FlaskSpeedInfo> GFlaskSpeedCont;	//nt:速率  int:位置索引
struct stItemSlot{
	stItemSlot() : slot_color_(kGSC_Invalid), index_(-1){}
	int				  index_;
	enCD_GemSlotColor slot_color_;
	GItemBasePtr	  gem_Item_;
};
//////////////////////////////////////////////////////////////////////////
class GEnsureAvoidSkill{
public:
	GEnsureAvoidSkill();
	~GEnsureAvoidSkill();

private:
	bool	old_enabled_;
};
//////////////////////////////////////////////////////////////////////////
//************************Open Visitor
//如果 is_pre_open == ture 只能做计算或者检测类的工作
class GOpenVisitor{
public:
	bool VisitNpc(const GNpc& npc, bool is_pre_open, enOpenVisitorRes& open_res);
	bool VisitMainSubPanelNormal(const GameObjBase& obj, bool is_pre_open, enOpenVisitorRes& open_res, pt_dword vtbl);
	bool VisitAreaTransition(GAreaTransition& area_transition, bool is_pre_open, enOpenVisitorRes& open_res);
	bool VisitWorldItem(const GWorldItem& world_item, bool is_pre_open, enOpenVisitorRes& open_res);
	bool VisitChestItem(const GChest& world_item, bool is_pre_open, enOpenVisitorRes& open_res);
	bool VisitTranstionable(const GTranstionable& transitionable, bool is_pre_open, enOpenVisitorRes& open_res);

public:
	static bool WaitCrossMap(const GClass::stLastMapInfo& last_map_info, GAreaTransition* last_area_transition);
};

//////////////////////////////////////////////////////////////////////////
class GHandleNpcTalkLabel : public Singleton<GHandleNpcTalkLabel, Singleton_MakeMe>{
public:
	class Handler{
	public:
		virtual enTalkToNpcRes PreHandle(const std::wstring& talk_label);
		virtual enTalkToNpcRes Handle(const std::wstring& talk_label);
	};
	typedef std::map<std::wstring, Handler*> Handlers;

public:
	GHandleNpcTalkLabel();
	enTalkToNpcRes PreHandleLabel(const std::wstring& talk_label);
	enTalkToNpcRes HandleLabel(const std::wstring& talk_label);
	static enTalkToNpcRes HandleCotinueImpl(bool wait_menu_panel);

private:
	Handlers		handlers_;
};
//////////////////////////////////////////////////////////////////////////
//补血补蓝计算
class GAutoEatHpMp{
public:
	GAutoEatHpMp(float hp_rate, float mp_rate);
	void SetRateInfo(float hp_rate, float mp_rate);
	bool CalcHpIndex(int& hp_index);
	bool CalcMpIndex(int& mp_index);
	bool CalcUtilityIndex(int& utility_index);

private:
	static bool CalcIdxImpl(float& last_rate, int& last_speed, float cur_rate, enCD_FlaskType flask_type, int& out_index);

private:
	float			last_hp_rate_;
	int				last_hp_speed_;
	float			last_mp_rate_;
	int				last_mp_speed_;
	float			hp_rate_;
	float			mp_rate_;
};


class GAutoUpDateGem{
public:
	typedef std::unordered_map<std::string, std::vector<std::string>> MapGemConT;
	struct stGemPosInfo
	{
		std::string  gem_name_;
		int			 index_;
		enCD_InventoryType dst_inventory_;
	};
	typedef std::vector<stGemPosInfo>  GemDstPos;
	typedef std::vector<GClass::stGemInfo>	 GemConT;
	typedef std::vector<GemConT> GemLinkCnt;

public:
	GAutoUpDateGem();
	void AddAutoGemLink(const std::string& main_gem, const luabind::object& tbl);
	void ClearAllGemLink();
	bool CalcAllGemPos(GemDstPos& gem_pos);

private:
	void FindSetCanWearEquip(GClass::VcSlotInfoConT& solt_info, std::vector<GClass::stGemInfo> gem, GemDstPos& gem_pos);
	bool CalcNeedLinkGem(GemLinkCnt& vec_link);

private:
	MapGemConT 		map_gem_;
};
//////////////////////////////////////////////////////////////////////////
class GFilterRect : public IFilterPos{
public:
	GFilterRect(const stVec2Int& left_bottom, const stVec2Int& right_top);
	void SetRect(const stVec2Int& left_bottom, const stVec2Int& right_top);
	bool DoFilt(const FittedType& obj) const override;

private:
	stRectInt		rect_;
};
//////////////////////////////////////////////////////////////////////////
class GScene_PreGameState : public CSH_PerHandler{
public:
	GScene_PreGameState(const luabind::object& fn) : CSH_PerHandler(fn){}
	bool InScene() const override;
	bool Handle() override;
};

class GScene_InGameState : public CSH_PerHandler{
public:
	GScene_InGameState(const luabind::object& fn) : CSH_PerHandler(fn){}
	bool InScene() const override;
	bool Handle() override;
};
//////////////////////////////////////////////////////////////////////////
//*****************exception
class GExcept_AvoidSkill : public CmnGeneralRunException{
public:
	GExcept_AvoidSkill();

	CMN_EXCEPTION_CLONE
};

//装备评分
class GEquipScore : public Singleton<GEquipScore, Singleton_MakeMe>{
	typedef std::map<pt_int, pt_int>  ConT;
	typedef std::map<enCD_GemSlotColor, pt_int> ColorConT;
	typedef std::map<enCD_ItemColor, pt_int> ItemConT;

public:
	GEquipScore(){};

public:
	pt_int CalcItemGoodValue(const GItemBase& item) const;
	pt_int CalcItemGoodValue(const GItemEquipBase& item) const;
	pt_int CalcItemGoodValue(const GItemFlask& item) const;
	void SetLinkScore(const luabind::object& lua_obj);
	void SetGemSlotRed(const luabind::object& lua_obj);
	void SetColorSocre(const luabind::object& lua_obj);
	void SetQuality(const luabind::object& lua_obj);

private:
	ConT		item_link_score_;
	ConT		item_gem_solt_red_;
	ConT		item_color_score_;
	pt_dword	item_quality_ratio_;
};

//////////////////////////////////////////////////////////////////////////