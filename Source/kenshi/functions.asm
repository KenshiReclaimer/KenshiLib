
.code

; forwarders

FUNC_BEGIN proc
FUNC_BEGIN endp

; InstanceID::getModIndex();
?getModIndex@InstanceID@@QEBAHXZ proc
jmp function_pointers[0*8]
?getModIndex@InstanceID@@QEBAHXZ endp

FUNC_SECOND proc
FUNC_SECOND endp

; InstanceID::getModIndex(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getModIndex@InstanceID@@SAFAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[1*8]
?getModIndex@InstanceID@@SAFAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_CONSTRUCTOR@InstanceID@@QEAAXAEBV1@@Z proc
?_CONSTRUCTOR@InstanceID@@QEAAXAEBV1@@Z endp

; InstanceID::InstanceID(const class InstanceID &);
??0InstanceID@@QEAA@AEBV0@@Z proc
jmp function_pointers[2*8]
??0InstanceID@@QEAA@AEBV0@@Z endp

?_CONSTRUCTOR@InstanceID@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVObjectInstance@GameData@@@Z proc
?_CONSTRUCTOR@InstanceID@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVObjectInstance@GameData@@@Z endp

; InstanceID::InstanceID(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class GameData::ObjectInstance &);
??0InstanceID@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVObjectInstance@GameData@@@Z proc
jmp function_pointers[3*8]
??0InstanceID@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVObjectInstance@GameData@@@Z endp

?_CONSTRUCTOR@InstanceID@@QEAAXXZ proc
?_CONSTRUCTOR@InstanceID@@QEAAXXZ endp

; InstanceID::InstanceID();
??0InstanceID@@QEAA@XZ proc
jmp function_pointers[4*8]
??0InstanceID@@QEAA@XZ endp

; InstanceID::assign(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?assign@InstanceID@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[5*8]
?assign@InstanceID@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; InstanceID::clear();
?clear@InstanceID@@QEAAXXZ proc
jmp function_pointers[6*8]
?clear@InstanceID@@QEAAXXZ endp

; InstanceID::needsSaving(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?needsSaving@InstanceID@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[7*8]
?needsSaving@InstanceID@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; InstanceID::notifyChange();
?notifyChange@InstanceID@@QEAAXXZ proc
jmp function_pointers[8*8]
?notifyChange@InstanceID@@QEAAXXZ endp

; InstanceID::hasChanges();
?hasChanges@InstanceID@@QEBA_NXZ proc
jmp function_pointers[9*8]
?hasChanges@InstanceID@@QEBA_NXZ endp

; InstanceID::notifySaved(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?notifySaved@InstanceID@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[10*8]
?notifySaved@InstanceID@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; InstanceID::empty();
?empty@InstanceID@@QEBA_NXZ proc
jmp function_pointers[11*8]
?empty@InstanceID@@QEBA_NXZ endp

; InstanceID::operator==(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
??8InstanceID@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[12*8]
??8InstanceID@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; InstanceID::getBaseIndex();
?getBaseIndex@InstanceID@@QEBAHXZ proc
jmp function_pointers[13*8]
?getBaseIndex@InstanceID@@QEBAHXZ endp

?_DESTRUCTOR@InstanceID@@QEAAXXZ proc
?_DESTRUCTOR@InstanceID@@QEAAXXZ endp

; InstanceID::~InstanceID();
??1InstanceID@@QEAA@XZ proc
jmp function_pointers[14*8]
??1InstanceID@@QEAA@XZ endp

; InstanceID::operator=(const class InstanceID &);
??4InstanceID@@QEAAAEAV0@AEBV0@@Z proc
jmp function_pointers[15*8]
??4InstanceID@@QEAAAEAV0@AEBV0@@Z endp

?_CONSTRUCTOR@GameSaveState@@QEAAXAEBV1@@Z proc
?_CONSTRUCTOR@GameSaveState@@QEAAXAEBV1@@Z endp

; GameSaveState::GameSaveState(const class GameSaveState &);
??0GameSaveState@@QEAA@AEBV0@@Z proc
jmp function_pointers[16*8]
??0GameSaveState@@QEAA@AEBV0@@Z endp

?_CONSTRUCTOR@GameSaveState@@QEAAXPEAVGameDataContainer@@PEAVGameData@@1AEBVPosRotPair@@PEAV4@PEAVInstanceID@@@Z proc
?_CONSTRUCTOR@GameSaveState@@QEAAXPEAVGameDataContainer@@PEAVGameData@@1AEBVPosRotPair@@PEAV4@PEAVInstanceID@@@Z endp

; GameSaveState::GameSaveState(class GameDataContainer *, class GameData *, class GameData *, const class PosRotPair &, class PosRotPair *, class InstanceID *);
??0GameSaveState@@QEAA@PEAVGameDataContainer@@PEAVGameData@@1AEBVPosRotPair@@PEAV3@PEAVInstanceID@@@Z proc
jmp function_pointers[17*8]
??0GameSaveState@@QEAA@PEAVGameDataContainer@@PEAVGameData@@1AEBVPosRotPair@@PEAV3@PEAVInstanceID@@@Z endp

?_CONSTRUCTOR@GameSaveState@@QEAAXXZ proc
?_CONSTRUCTOR@GameSaveState@@QEAAXXZ endp

; GameSaveState::GameSaveState();
??0GameSaveState@@QEAA@XZ proc
jmp function_pointers[18*8]
??0GameSaveState@@QEAA@XZ endp

; GameSaveState::generateNewInstanceID();
?generateNewInstanceID@GameSaveState@@QEAAXXZ proc
jmp function_pointers[19*8]
?generateNewInstanceID@GameSaveState@@QEAAXXZ endp

; GameSaveState::createFromSerialisedInstanceData(class GameDataContainer *, class GameData::ObjectInstance *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?createFromSerialisedInstanceData@GameSaveState@@QEAAXPEAVGameDataContainer@@PEAVObjectInstance@GameData@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[20*8]
?createFromSerialisedInstanceData@GameSaveState@@QEAAXPEAVGameDataContainer@@PEAVObjectInstance@GameData@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameSaveState::generateStateID(enum itemType);
?generateStateID@GameSaveState@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4itemType@@@Z proc
jmp function_pointers[21*8]
?generateStateID@GameSaveState@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4itemType@@@Z endp

; GameSaveState::createState(enum itemType);
?createState@GameSaveState@@QEAAPEAVGameData@@W4itemType@@@Z proc
jmp function_pointers[22*8]
?createState@GameSaveState@@QEAAPEAVGameData@@W4itemType@@@Z endp

; GameSaveState::addState(class GameData *);
?addState@GameSaveState@@QEAAXPEAVGameData@@@Z proc
jmp function_pointers[23*8]
?addState@GameSaveState@@QEAAXPEAVGameData@@@Z endp

; GameSaveState::hasState(enum itemType);
?hasState@GameSaveState@@QEBA_NW4itemType@@@Z proc
jmp function_pointers[24*8]
?hasState@GameSaveState@@QEBA_NW4itemType@@@Z endp

; GameSaveState::getState(enum itemType);
?getState@GameSaveState@@QEAAPEAVGameData@@W4itemType@@@Z proc
jmp function_pointers[25*8]
?getState@GameSaveState@@QEAAPEAVGameData@@W4itemType@@@Z endp

; GameSaveState::numStates();
?numStates@GameSaveState@@QEBAHXZ proc
jmp function_pointers[26*8]
?numStates@GameSaveState@@QEBAHXZ endp

; GameSaveState::getPos();
?getPos@GameSaveState@@QEBA?AVVector3@Ogre@@XZ proc
jmp function_pointers[27*8]
?getPos@GameSaveState@@QEBA?AVVector3@Ogre@@XZ endp

; GameSaveState::getRot();
?getRot@GameSaveState@@QEBA?AVQuaternion@Ogre@@XZ proc
jmp function_pointers[28*8]
?getRot@GameSaveState@@QEBA?AVQuaternion@Ogre@@XZ endp

; GameSaveState::getInstanceID();
?getInstanceID@GameSaveState@@QEBA?AVInstanceID@@XZ proc
jmp function_pointers[29*8]
?getInstanceID@GameSaveState@@QEBA?AVInstanceID@@XZ endp

; symbol is too long
; ?getAllStates@GameSaveState@@QEBAAEBV?$unordered_map@W4itemType@@PEAVGameData@@U?$hash@W4itemType@@@boost@@U?$equal_to@W4itemType@@@std@@V?$STLAllocator@U?$pair@$$CBW4itemType@@PEAVGameData@@@std@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@XZ
; GameSaveState::getAllStates();
GameSaveState_getAllStates_PLACEHOLDER proc
jmp function_pointers[30*8]
GameSaveState_getAllStates_PLACEHOLDER endp

; GameSaveState::operator bool();
??BGameSaveState@@QEBA_NXZ proc
jmp function_pointers[31*8]
??BGameSaveState@@QEBA_NXZ endp

; GameSaveState::getTheInstancesData();
?getTheInstancesData@GameSaveState@@QEAAPEAVGameData@@XZ proc
jmp function_pointers[32*8]
?getTheInstancesData@GameSaveState@@QEAAPEAVGameData@@XZ endp

?_DESTRUCTOR@GameSaveState@@QEAAXXZ proc
?_DESTRUCTOR@GameSaveState@@QEAAXXZ endp

; GameSaveState::~GameSaveState();
??1GameSaveState@@QEAA@XZ proc
jmp function_pointers[33*8]
??1GameSaveState@@QEAA@XZ endp

?_CONSTRUCTOR@RootObjectBase@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z proc
?_CONSTRUCTOR@RootObjectBase@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z endp

; RootObjectBase::RootObjectBase(class GameData *, class Faction *, class hand);
??0RootObjectBase@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z proc
jmp function_pointers[34*8]
??0RootObjectBase@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z endp

?_DESTRUCTOR@RootObjectBase@@QEAAXXZ proc
?_DESTRUCTOR@RootObjectBase@@QEAAXXZ endp

; RootObjectBase::~RootObjectBase();
??1RootObjectBase@@UEAA@XZ proc
jmp function_pointers[35*8]
??1RootObjectBase@@UEAA@XZ endp

; RootObjectBase::isValid();
?isValid@RootObjectBase@@QEBA_NXZ proc
jmp function_pointers[36*8]
?isValid@RootObjectBase@@QEBA_NXZ endp

?_NV_getName@RootObjectBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
?_NV_getName@RootObjectBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; RootObjectBase::getName();
?getName@RootObjectBase@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[37*8]
?getName@RootObjectBase@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

?_NV_setName@RootObjectBase@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_setName@RootObjectBase@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; RootObjectBase::setName(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?setName@RootObjectBase@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[38*8]
?setName@RootObjectBase@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_getGameData@RootObjectBase@@QEBAPEAVGameData@@XZ proc
?_NV_getGameData@RootObjectBase@@QEBAPEAVGameData@@XZ endp

; RootObjectBase::getGameData();
?getGameData@RootObjectBase@@UEBAPEAVGameData@@XZ proc
jmp function_pointers[39*8]
?getGameData@RootObjectBase@@UEBAPEAVGameData@@XZ endp

?_NV_getDataType@RootObjectBase@@QEBA?AW4itemType@@XZ proc
?_NV_getDataType@RootObjectBase@@QEBA?AW4itemType@@XZ endp

; RootObjectBase::getDataType();
?getDataType@RootObjectBase@@UEBA?AW4itemType@@XZ proc
jmp function_pointers[40*8]
?getDataType@RootObjectBase@@UEBA?AW4itemType@@XZ endp

?_NV_typeIsAnItem@RootObjectBase@@QEBA_NXZ proc
?_NV_typeIsAnItem@RootObjectBase@@QEBA_NXZ endp

; RootObjectBase::typeIsAnItem();
?typeIsAnItem@RootObjectBase@@UEBA_NXZ proc
jmp function_pointers[41*8]
?typeIsAnItem@RootObjectBase@@UEBA_NXZ endp

?_NV_isUnconcious@RootObjectBase@@QEBA_NXZ proc
?_NV_isUnconcious@RootObjectBase@@QEBA_NXZ endp

; RootObjectBase::isUnconcious();
?isUnconcious@RootObjectBase@@UEBA_NXZ proc
jmp function_pointers[42*8]
?isUnconcious@RootObjectBase@@UEBA_NXZ endp

?_NV_getPositionForWaypoint@RootObjectBase@@QEAA?AVVector3@Ogre@@AEBV23@@Z proc
?_NV_getPositionForWaypoint@RootObjectBase@@QEAA?AVVector3@Ogre@@AEBV23@@Z endp

; RootObjectBase::getPositionForWaypoint(const class Ogre::Vector3 &);
?getPositionForWaypoint@RootObjectBase@@UEAA?AVVector3@Ogre@@AEBV23@@Z proc
jmp function_pointers[43*8]
?getPositionForWaypoint@RootObjectBase@@UEAA?AVVector3@Ogre@@AEBV23@@Z endp

?_NV_getPosition@RootObjectBase@@QEAA?AVVector3@Ogre@@XZ proc
?_NV_getPosition@RootObjectBase@@QEAA?AVVector3@Ogre@@XZ endp

; RootObjectBase::getPosition();
?getPosition@RootObjectBase@@UEAA?AVVector3@Ogre@@XZ proc
jmp function_pointers[44*8]
?getPosition@RootObjectBase@@UEAA?AVVector3@Ogre@@XZ endp

?_NV_getMovementSpeed@RootObjectBase@@QEBAMXZ proc
?_NV_getMovementSpeed@RootObjectBase@@QEBAMXZ endp

; RootObjectBase::getMovementSpeed();
?getMovementSpeed@RootObjectBase@@UEBAMXZ proc
jmp function_pointers[45*8]
?getMovementSpeed@RootObjectBase@@UEBAMXZ endp

?_NV_getMovementDirection@RootObjectBase@@QEBA?AVVector3@Ogre@@XZ proc
?_NV_getMovementDirection@RootObjectBase@@QEBA?AVVector3@Ogre@@XZ endp

; RootObjectBase::getMovementDirection();
?getMovementDirection@RootObjectBase@@UEBA?AVVector3@Ogre@@XZ proc
jmp function_pointers[46*8]
?getMovementDirection@RootObjectBase@@UEBA?AVVector3@Ogre@@XZ endp

?_NV_getFaction@RootObjectBase@@QEBAPEAVFaction@@XZ proc
?_NV_getFaction@RootObjectBase@@QEBAPEAVFaction@@XZ endp

; RootObjectBase::getFaction();
?getFaction@RootObjectBase@@UEBAPEAVFaction@@XZ proc
jmp function_pointers[47*8]
?getFaction@RootObjectBase@@UEBAPEAVFaction@@XZ endp

; RootObjectBase::hasFaction();
?hasFaction@RootObjectBase@@QEBA_NXZ proc
jmp function_pointers[48*8]
?hasFaction@RootObjectBase@@QEBA_NXZ endp

?_NV_getFloor@RootObjectBase@@QEBAHXZ proc
?_NV_getFloor@RootObjectBase@@QEBAHXZ endp

; RootObjectBase::getFloor();
?getFloor@RootObjectBase@@UEBAHXZ proc
jmp function_pointers[49*8]
?getFloor@RootObjectBase@@UEBAHXZ endp

?_NV_getSensoryData@RootObjectBase@@QEAAPEAVSensoryData@@XZ proc
?_NV_getSensoryData@RootObjectBase@@QEAAPEAVSensoryData@@XZ endp

; RootObjectBase::getSensoryData();
?getSensoryData@RootObjectBase@@UEAAPEAVSensoryData@@XZ proc
jmp function_pointers[50*8]
?getSensoryData@RootObjectBase@@UEAAPEAVSensoryData@@XZ endp

?_NV_getStateBroadcast@RootObjectBase@@QEAAPEAVStateBroadcastData@@XZ proc
?_NV_getStateBroadcast@RootObjectBase@@QEAAPEAVStateBroadcastData@@XZ endp

; RootObjectBase::getStateBroadcast();
?getStateBroadcast@RootObjectBase@@UEAAPEAVStateBroadcastData@@XZ proc
jmp function_pointers[51*8]
?getStateBroadcast@RootObjectBase@@UEAAPEAVStateBroadcastData@@XZ endp

?_NV_getCurrentTownLocation@RootObjectBase@@QEAAPEAVTownBase@@XZ proc
?_NV_getCurrentTownLocation@RootObjectBase@@QEAAPEAVTownBase@@XZ endp

; RootObjectBase::getCurrentTownLocation();
?getCurrentTownLocation@RootObjectBase@@UEAAPEAVTownBase@@XZ proc
jmp function_pointers[52*8]
?getCurrentTownLocation@RootObjectBase@@UEAAPEAVTownBase@@XZ endp

; RootObjectBase::getHandle();
?getHandle@RootObjectBase@@QEBAAEBVhand@@XZ proc
jmp function_pointers[53*8]
?getHandle@RootObjectBase@@QEBAAEBVhand@@XZ endp

?_NV_setHandle@RootObjectBase@@QEAAXAEBVhand@@@Z proc
?_NV_setHandle@RootObjectBase@@QEAAXAEBVhand@@@Z endp

; RootObjectBase::setHandle(const class hand &);
?setHandle@RootObjectBase@@UEAAXAEBVhand@@@Z proc
jmp function_pointers[54*8]
?setHandle@RootObjectBase@@UEAAXAEBVhand@@@Z endp

?_NV_getOwnerships@RootObjectBase@@QEAAPEAVOwnerships@@XZ proc
?_NV_getOwnerships@RootObjectBase@@QEAAPEAVOwnerships@@XZ endp

; RootObjectBase::getOwnerships();
?getOwnerships@RootObjectBase@@UEAAPEAVOwnerships@@XZ proc
jmp function_pointers[55*8]
?getOwnerships@RootObjectBase@@UEAAPEAVOwnerships@@XZ endp

?_NV_setFaction@RootObjectBase@@QEAAXPEAVFaction@@PEAVActivePlatoon@@@Z proc
?_NV_setFaction@RootObjectBase@@QEAAXPEAVFaction@@PEAVActivePlatoon@@@Z endp

; RootObjectBase::setFaction(class Faction *, class ActivePlatoon *);
?setFaction@RootObjectBase@@UEAAXPEAVFaction@@PEAVActivePlatoon@@@Z proc
jmp function_pointers[56*8]
?setFaction@RootObjectBase@@UEAAXPEAVFaction@@PEAVActivePlatoon@@@Z endp

?_CONSTRUCTOR@RootObject@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z proc
?_CONSTRUCTOR@RootObject@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z endp

; RootObject::RootObject(class GameData *, class Faction *, class hand);
??0RootObject@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z proc
jmp function_pointers[57*8]
??0RootObject@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z endp

?_DESTRUCTOR@RootObject@@QEAAXXZ proc
?_DESTRUCTOR@RootObject@@QEAAXXZ endp

; RootObject::~RootObject();
??1RootObject@@UEAA@XZ proc
jmp function_pointers[58*8]
??1RootObject@@UEAA@XZ endp

?_NV_needsSaving@RootObject@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_needsSaving@RootObject@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; RootObject::needsSaving(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?needsSaving@RootObject@@UEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[59*8]
?needsSaving@RootObject@@UEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_getInstanceID@RootObject@@QEAAPEAVInstanceID@@XZ proc
?_NV_getInstanceID@RootObject@@QEAAPEAVInstanceID@@XZ endp

; RootObject::getInstanceID();
?getInstanceID@RootObject@@UEAAPEAVInstanceID@@XZ proc
jmp function_pointers[60*8]
?getInstanceID@RootObject@@UEAAPEAVInstanceID@@XZ endp

?_NV_getLayoutInstanceID@RootObject@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
?_NV_getLayoutInstanceID@RootObject@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; RootObject::getLayoutInstanceID();
?getLayoutInstanceID@RootObject@@UEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[61*8]
?getLayoutInstanceID@RootObject@@UEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

?_NV_getOrientation@RootObject@@QEBA?AVQuaternion@Ogre@@XZ proc
?_NV_getOrientation@RootObject@@QEBA?AVQuaternion@Ogre@@XZ endp

; RootObject::getOrientation();
?getOrientation@RootObject@@UEBA?AVQuaternion@Ogre@@XZ proc
jmp function_pointers[62*8]
?getOrientation@RootObject@@UEBA?AVQuaternion@Ogre@@XZ endp

?_NV_getZoneMapLocation@RootObject@@QEAAPEAVZoneMap@@XZ proc
?_NV_getZoneMapLocation@RootObject@@QEAAPEAVZoneMap@@XZ endp

; RootObject::getZoneMapLocation();
?getZoneMapLocation@RootObject@@UEAAPEAVZoneMap@@XZ proc
jmp function_pointers[63*8]
?getZoneMapLocation@RootObject@@UEAAPEAVZoneMap@@XZ endp

?_NV_getRace@RootObject@@QEBAPEAVRaceData@@XZ proc
?_NV_getRace@RootObject@@QEBAPEAVRaceData@@XZ endp

; RootObject::getRace();
?getRace@RootObject@@UEBAPEAVRaceData@@XZ proc
jmp function_pointers[64*8]
?getRace@RootObject@@UEBAPEAVRaceData@@XZ endp

?_NV_threadedUpdate@RootObject@@QEAAXXZ proc
?_NV_threadedUpdate@RootObject@@QEAAXXZ endp

; RootObject::threadedUpdate();
?threadedUpdate@RootObject@@UEAAXXZ proc
jmp function_pointers[65*8]
?threadedUpdate@RootObject@@UEAAXXZ endp

?_NV_update@RootObject@@QEAAXXZ proc
?_NV_update@RootObject@@QEAAXXZ endp

; RootObject::update();
?update@RootObject@@UEAAXXZ proc
jmp function_pointers[66*8]
?update@RootObject@@UEAAXXZ endp

?_NV_periodicUpdate@RootObject@@QEAAXXZ proc
?_NV_periodicUpdate@RootObject@@QEAAXXZ endp

; RootObject::periodicUpdate();
?periodicUpdate@RootObject@@UEAAXXZ proc
jmp function_pointers[67*8]
?periodicUpdate@RootObject@@UEAAXXZ endp

?_NV_getAABB@RootObject@@QEBAAEBUAabb@Ogre@@XZ proc
?_NV_getAABB@RootObject@@QEBAAEBUAabb@Ogre@@XZ endp

; RootObject::getAABB();
?getAABB@RootObject@@UEBAAEBUAabb@Ogre@@XZ proc
jmp function_pointers[68*8]
?getAABB@RootObject@@UEBAAEBUAabb@Ogre@@XZ endp

?_NV_getVisible@RootObject@@QEBA_NXZ proc
?_NV_getVisible@RootObject@@QEBA_NXZ endp

; RootObject::getVisible();
?getVisible@RootObject@@UEBA_NXZ proc
jmp function_pointers[69*8]
?getVisible@RootObject@@UEBA_NXZ endp

?_NV_isDisabled@RootObject@@QEAA_NXZ proc
?_NV_isDisabled@RootObject@@QEAA_NXZ endp

; RootObject::isDisabled();
?isDisabled@RootObject@@UEAA_NXZ proc
jmp function_pointers[70*8]
?isDisabled@RootObject@@UEAA_NXZ endp

?_NV_setFaction@RootObject@@QEAAXPEAVFaction@@PEAVActivePlatoon@@@Z proc
?_NV_setFaction@RootObject@@QEAAXPEAVFaction@@PEAVActivePlatoon@@@Z endp

; RootObject::setFaction(class Faction *, class ActivePlatoon *);
?setFaction@RootObject@@UEAAXPEAVFaction@@PEAVActivePlatoon@@@Z proc
jmp function_pointers[71*8]
?setFaction@RootObject@@UEAAXPEAVFaction@@PEAVActivePlatoon@@@Z endp

?_NV_amInsideTownWalls@RootObject@@QEAAHXZ proc
?_NV_amInsideTownWalls@RootObject@@QEAAHXZ endp

; RootObject::amInsideTownWalls();
?amInsideTownWalls@RootObject@@UEAAHXZ proc
jmp function_pointers[72*8]
?amInsideTownWalls@RootObject@@UEAAHXZ endp

?_NV_setInsideTownWalls@RootObject@@QEAAXH@Z proc
?_NV_setInsideTownWalls@RootObject@@QEAAXH@Z endp

; RootObject::setInsideTownWalls(int);
?setInsideTownWalls@RootObject@@UEAAXH@Z proc
jmp function_pointers[73*8]
?setInsideTownWalls@RootObject@@UEAAXH@Z endp

?_NV_getFloor@RootObject@@QEBAHXZ proc
?_NV_getFloor@RootObject@@QEBAHXZ endp

; RootObject::getFloor();
?getFloor@RootObject@@UEBAHXZ proc
jmp function_pointers[74*8]
?getFloor@RootObject@@UEBAHXZ endp

?_NV_setFloor@RootObject@@QEAAXH@Z proc
?_NV_setFloor@RootObject@@QEAAXH@Z endp

; RootObject::setFloor(int);
?setFloor@RootObject@@UEAAXH@Z proc
jmp function_pointers[75*8]
?setFloor@RootObject@@UEAAXH@Z endp

?_NV_select@RootObject@@QEAAXXZ proc
?_NV_select@RootObject@@QEAAXXZ endp

; RootObject::select();
?select@RootObject@@UEAAXXZ proc
jmp function_pointers[76*8]
?select@RootObject@@UEAAXXZ endp

?_NV_unselect@RootObject@@QEAAXXZ proc
?_NV_unselect@RootObject@@QEAAXXZ endp

; RootObject::unselect();
?unselect@RootObject@@UEAAXXZ proc
jmp function_pointers[77*8]
?unselect@RootObject@@UEAAXXZ endp

?_NV_getGUIData@RootObject@@QEAAXPEAVDatapanelGUI@@H@Z proc
?_NV_getGUIData@RootObject@@QEAAXPEAVDatapanelGUI@@H@Z endp

; RootObject::getGUIData(class DatapanelGUI *, int);
?getGUIData@RootObject@@UEAAXPEAVDatapanelGUI@@H@Z proc
jmp function_pointers[78*8]
?getGUIData@RootObject@@UEAAXPEAVDatapanelGUI@@H@Z endp

?_NV_getGUIDataCategories@RootObject@@QEAAXAEAV?$lektor@VStringPair@@@@@Z proc
?_NV_getGUIDataCategories@RootObject@@QEAAXAEAV?$lektor@VStringPair@@@@@Z endp

; RootObject::getGUIDataCategories(class lektor<StringPair> &);
?getGUIDataCategories@RootObject@@UEAAXAEAV?$lektor@VStringPair@@@@@Z proc
jmp function_pointers[79*8]
?getGUIDataCategories@RootObject@@UEAAXAEAV?$lektor@VStringPair@@@@@Z endp

?_NV_setStandingOrder@RootObject@@QEAAXW4StandingOrder@MessageForB@@@Z proc
?_NV_setStandingOrder@RootObject@@QEAAXW4StandingOrder@MessageForB@@@Z endp

; RootObject::setStandingOrder(enum MessageForB::StandingOrder);
?setStandingOrder@RootObject@@UEAAXW4StandingOrder@MessageForB@@@Z proc
jmp function_pointers[80*8]
?setStandingOrder@RootObject@@UEAAXW4StandingOrder@MessageForB@@@Z endp

?_NV_getOrders@RootObject@@QEAAXAEAV?$lektor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@@Z proc
?_NV_getOrders@RootObject@@QEAAXAEAV?$lektor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@@Z endp

; RootObject::getOrders(class lektor<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > &);
?getOrders@RootObject@@UEAAXAEAV?$lektor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@@Z proc
jmp function_pointers[81*8]
?getOrders@RootObject@@UEAAXAEAV?$lektor@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@@Z endp

?_NV_getInventory@RootObject@@QEBAPEAVInventory@@XZ proc
?_NV_getInventory@RootObject@@QEBAPEAVInventory@@XZ endp

; RootObject::getInventory();
?getInventory@RootObject@@UEBAPEAVInventory@@XZ proc
jmp function_pointers[82*8]
?getInventory@RootObject@@UEBAPEAVInventory@@XZ endp

?_NV_giveItem@RootObject@@QEAA_NPEAVItem@@_N1@Z proc
?_NV_giveItem@RootObject@@QEAA_NPEAVItem@@_N1@Z endp

; RootObject::giveItem(class Item *, bool, bool);
?giveItem@RootObject@@UEAA_NPEAVItem@@_N1@Z proc
jmp function_pointers[83*8]
?giveItem@RootObject@@UEAA_NPEAVItem@@_N1@Z endp

?_NV_hasRoomForItem@RootObject@@QEAA_NPEAVGameData@@@Z proc
?_NV_hasRoomForItem@RootObject@@QEAA_NPEAVGameData@@@Z endp

; RootObject::hasRoomForItem(class GameData *);
?hasRoomForItem@RootObject@@UEAA_NPEAVGameData@@@Z proc
jmp function_pointers[84*8]
?hasRoomForItem@RootObject@@UEAA_NPEAVGameData@@@Z endp

?_NV_hasItem@RootObject@@QEAA_NPEAVGameData@@@Z proc
?_NV_hasItem@RootObject@@QEAA_NPEAVGameData@@@Z endp

; RootObject::hasItem(class GameData *);
?hasItem@RootObject@@UEAA_NPEAVGameData@@@Z proc
jmp function_pointers[85*8]
?hasItem@RootObject@@UEAA_NPEAVGameData@@@Z endp

?_NV_createInventoryLayout@RootObject@@QEAAPEAVInventoryLayout@@XZ proc
?_NV_createInventoryLayout@RootObject@@QEAAPEAVInventoryLayout@@XZ endp

; RootObject::createInventoryLayout();
?createInventoryLayout@RootObject@@UEAAPEAVInventoryLayout@@XZ proc
jmp function_pointers[86*8]
?createInventoryLayout@RootObject@@UEAAPEAVInventoryLayout@@XZ endp

?_NV_ImStealingDoYouNotice@RootObject@@QEAA_NPEAV1@@Z proc
?_NV_ImStealingDoYouNotice@RootObject@@QEAA_NPEAV1@@Z endp

; RootObject::ImStealingDoYouNotice(class RootObject *);
?ImStealingDoYouNotice@RootObject@@UEAA_NPEAV1@@Z proc
jmp function_pointers[87*8]
?ImStealingDoYouNotice@RootObject@@UEAA_NPEAV1@@Z endp

?_NV_stolenGoodsDetectionCheck@RootObject@@QEAA_NPEAVItem@@PEAV1@@Z proc
?_NV_stolenGoodsDetectionCheck@RootObject@@QEAA_NPEAVItem@@PEAV1@@Z endp

; RootObject::stolenGoodsDetectionCheck(class Item *, class RootObject *);
?stolenGoodsDetectionCheck@RootObject@@UEAA_NPEAVItem@@PEAV1@@Z proc
jmp function_pointers[88*8]
?stolenGoodsDetectionCheck@RootObject@@UEAA_NPEAVItem@@PEAV1@@Z endp

?_NV_equipItem@RootObject@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
?_NV_equipItem@RootObject@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

; RootObject::equipItem(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Item *);
?equipItem@RootObject@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
jmp function_pointers[89*8]
?equipItem@RootObject@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

?_NV_unequipItem@RootObject@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
?_NV_unequipItem@RootObject@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

; RootObject::unequipItem(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Item *);
?unequipItem@RootObject@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
jmp function_pointers[90*8]
?unequipItem@RootObject@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

?_NV_dropItem@RootObject@@QEAAXPEAV1@@Z proc
?_NV_dropItem@RootObject@@QEAAXPEAV1@@Z endp

; RootObject::dropItem(class RootObject *);
?dropItem@RootObject@@UEAAXPEAV1@@Z proc
jmp function_pointers[91*8]
?dropItem@RootObject@@UEAAXPEAV1@@Z endp

?_NV_takeMoney@RootObject@@QEAA_NH@Z proc
?_NV_takeMoney@RootObject@@QEAA_NH@Z endp

; RootObject::takeMoney(int);
?takeMoney@RootObject@@UEAA_NH@Z proc
jmp function_pointers[92*8]
?takeMoney@RootObject@@UEAA_NH@Z endp

?_NV_getMoney@RootObject@@QEBAHXZ proc
?_NV_getMoney@RootObject@@QEBAHXZ endp

; RootObject::getMoney();
?getMoney@RootObject@@UEBAHXZ proc
jmp function_pointers[93*8]
?getMoney@RootObject@@UEBAHXZ endp

?_NV_say@RootObject@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_say@RootObject@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; RootObject::say(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?say@RootObject@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[94*8]
?say@RootObject@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_notifyIndoors@RootObject@@QEAAXAEBVhand@@@Z proc
?_NV_notifyIndoors@RootObject@@QEAAXAEBVhand@@@Z endp

; RootObject::notifyIndoors(const class hand &);
?notifyIndoors@RootObject@@UEAAXAEBVhand@@@Z proc
jmp function_pointers[95*8]
?notifyIndoors@RootObject@@UEAAXAEBVhand@@@Z endp

?_NV_notifyOutdoors@RootObject@@QEAAXXZ proc
?_NV_notifyOutdoors@RootObject@@QEAAXXZ endp

; RootObject::notifyOutdoors();
?notifyOutdoors@RootObject@@UEAAXXZ proc
jmp function_pointers[96*8]
?notifyOutdoors@RootObject@@UEAAXXZ endp

?_NV_isIndoors@RootObject@@QEBAAEBVhand@@XZ proc
?_NV_isIndoors@RootObject@@QEBAAEBVhand@@XZ endp

; RootObject::isIndoors();
?isIndoors@RootObject@@UEBAAEBVhand@@XZ proc
jmp function_pointers[97*8]
?isIndoors@RootObject@@UEBAAEBVhand@@XZ endp

?_NV_isOnARoof@RootObject@@QEAA_NXZ proc
?_NV_isOnARoof@RootObject@@QEAA_NXZ endp

; RootObject::isOnARoof();
?isOnARoof@RootObject@@UEAA_NXZ proc
jmp function_pointers[98*8]
?isOnARoof@RootObject@@UEAA_NXZ endp

?_NV_getIntendedAggression@RootObject@@QEAAMXZ proc
?_NV_getIntendedAggression@RootObject@@QEAAMXZ endp

; RootObject::getIntendedAggression();
?getIntendedAggression@RootObject@@UEAAMXZ proc
jmp function_pointers[99*8]
?getIntendedAggression@RootObject@@UEAAMXZ endp

?_NV_hitByMeleeAttack@RootObject@@QEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAVCharacter@@PEAVCombatTechniqueData@@H@Z proc
?_NV_hitByMeleeAttack@RootObject@@QEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAVCharacter@@PEAVCombatTechniqueData@@H@Z endp

; RootObject::hitByMeleeAttack(enum CutDirection, class Damages &, class Character *, class CombatTechniqueData *, int);
?hitByMeleeAttack@RootObject@@UEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAVCharacter@@PEAVCombatTechniqueData@@H@Z proc
jmp function_pointers[100*8]
?hitByMeleeAttack@RootObject@@UEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAVCharacter@@PEAVCombatTechniqueData@@H@Z endp

?_NV_getPlatoonAI@RootObject@@QEAAPEAVPlatoonAI@@XZ proc
?_NV_getPlatoonAI@RootObject@@QEAAPEAVPlatoonAI@@XZ endp

; RootObject::getPlatoonAI();
?getPlatoonAI@RootObject@@UEAAPEAVPlatoonAI@@XZ proc
jmp function_pointers[101*8]
?getPlatoonAI@RootObject@@UEAAPEAVPlatoonAI@@XZ endp

?_NV_setIsInsideBuilding@RootObject@@QEAAXAEBVhand@@@Z proc
?_NV_setIsInsideBuilding@RootObject@@QEAAXAEBVhand@@@Z endp

; RootObject::setIsInsideBuilding(const class hand &);
?setIsInsideBuilding@RootObject@@UEAAXAEBVhand@@@Z proc
jmp function_pointers[102*8]
?setIsInsideBuilding@RootObject@@UEAAXAEBVhand@@@Z endp

?_NV_notifyEffect@RootObject@@QEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z proc
?_NV_notifyEffect@RootObject@@QEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z endp

; RootObject::notifyEffect(enum EffectType::Enum, enum WeatherAffecting, float);
?notifyEffect@RootObject@@UEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z proc
jmp function_pointers[103*8]
?notifyEffect@RootObject@@UEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z endp

?_NV_loadUnloadCheck@RootObject@@QEAAXXZ proc
?_NV_loadUnloadCheck@RootObject@@QEAAXXZ endp

; RootObject::loadUnloadCheck();
?loadUnloadCheck@RootObject@@UEAAXXZ proc
jmp function_pointers[104*8]
?loadUnloadCheck@RootObject@@UEAAXXZ endp

?_CONSTRUCTOR@Character@@QEAAXPEAVGameData@@PEAVFaction@@AEBVhand@@@Z proc
?_CONSTRUCTOR@Character@@QEAAXPEAVGameData@@PEAVFaction@@AEBVhand@@@Z endp

; Character::Character(class GameData *, class Faction *, const class hand &);
??0Character@@QEAA@PEAVGameData@@PEAVFaction@@AEBVhand@@@Z proc
jmp function_pointers[105*8]
??0Character@@QEAA@PEAVGameData@@PEAVFaction@@AEBVhand@@@Z endp

; Character::isImmuneToOffscreenMode();
?isImmuneToOffscreenMode@Character@@QEAA_NXZ proc
jmp function_pointers[106*8]
?isImmuneToOffscreenMode@Character@@QEAA_NXZ endp

?_NV_init@Character@@QEAAXXZ proc
?_NV_init@Character@@QEAAXXZ endp

; Character::init();
?init@Character@@UEAAXXZ proc
jmp function_pointers[107*8]
?init@Character@@UEAAXXZ endp

?_DESTRUCTOR@Character@@QEAAXXZ proc
?_DESTRUCTOR@Character@@QEAAXXZ endp

; Character::~Character();
??1Character@@UEAA@XZ proc
jmp function_pointers[108*8]
??1Character@@UEAA@XZ endp

?_NV_isOnARoof@Character@@QEAA_NXZ proc
?_NV_isOnARoof@Character@@QEAA_NXZ endp

; Character::isOnARoof();
?isOnARoof@Character@@UEAA_NXZ proc
jmp function_pointers[109*8]
?isOnARoof@Character@@UEAA_NXZ endp

?_NV_isOnAWall@Character@@QEAA_NXZ proc
?_NV_isOnAWall@Character@@QEAA_NXZ endp

; Character::isOnAWall();
?isOnAWall@Character@@UEAA_NXZ proc
jmp function_pointers[110*8]
?isOnAWall@Character@@UEAA_NXZ endp

; Character::getLightLevel();
?getLightLevel@Character@@QEAAMXZ proc
jmp function_pointers[111*8]
?getLightLevel@Character@@QEAAMXZ endp

?_NV_getHPMultiplier@Character@@QEBAMXZ proc
?_NV_getHPMultiplier@Character@@QEBAMXZ endp

; Character::getHPMultiplier();
?getHPMultiplier@Character@@UEBAMXZ proc
jmp function_pointers[112*8]
?getHPMultiplier@Character@@UEBAMXZ endp

; Character::healCompletely();
?healCompletely@Character@@QEAAXXZ proc
jmp function_pointers[113*8]
?healCompletely@Character@@QEAAXXZ endp

; Character::resetRagdollNavmeshSafePos();
?resetRagdollNavmeshSafePos@Character@@QEAAXXZ proc
jmp function_pointers[114*8]
?resetRagdollNavmeshSafePos@Character@@QEAAXXZ endp

; Character::setRagdollNavmeshSafePos();
?setRagdollNavmeshSafePos@Character@@QEAAXXZ proc
jmp function_pointers[115*8]
?setRagdollNavmeshSafePos@Character@@QEAAXXZ endp

; Character::getFrameTime();
?getFrameTime@Character@@QEBAMXZ proc
jmp function_pointers[116*8]
?getFrameTime@Character@@QEBAMXZ endp

; Character::frameSkip();
?frameSkip@Character@@QEAAXXZ proc
jmp function_pointers[117*8]
?frameSkip@Character@@QEAAXXZ endp

; Character::getCurrentNoiseRange();
?getCurrentNoiseRange@Character@@QEAAMXZ proc
jmp function_pointers[118*8]
?getCurrentNoiseRange@Character@@QEAAMXZ endp

?_NV_isDestroyed@Character@@QEBA_NXZ proc
?_NV_isDestroyed@Character@@QEBA_NXZ endp

; Character::isDestroyed();
?isDestroyed@Character@@UEBA_NXZ proc
jmp function_pointers[119*8]
?isDestroyed@Character@@UEBA_NXZ endp

; Character::isLawEnforcement();
?isLawEnforcement@Character@@QEAA_NXZ proc
jmp function_pointers[120*8]
?isLawEnforcement@Character@@QEAA_NXZ endp

; Character::canAssignBounties();
?canAssignBounties@Character@@QEAA_NXZ proc
jmp function_pointers[121*8]
?canAssignBounties@Character@@QEAA_NXZ endp

?_NV_getDataType@Character@@QEBA?AW4itemType@@XZ proc
?_NV_getDataType@Character@@QEBA?AW4itemType@@XZ endp

; Character::getDataType();
?getDataType@Character@@UEBA?AW4itemType@@XZ proc
jmp function_pointers[122*8]
?getDataType@Character@@UEBA?AW4itemType@@XZ endp

; Character::isDiplomaticStatus(bool);
?isDiplomaticStatus@Character@@QEAA_N_N@Z proc
jmp function_pointers[123*8]
?isDiplomaticStatus@Character@@QEAA_N_N@Z endp

; Character::isLeadingAWarCampaign();
?isLeadingAWarCampaign@Character@@QEAA_NXZ proc
jmp function_pointers[124*8]
?isLeadingAWarCampaign@Character@@QEAA_NXZ endp

; Character::isInAWarCampaign();
?isInAWarCampaign@Character@@QEAAPEAVCampaignInstance@@XZ proc
jmp function_pointers[125*8]
?isInAWarCampaign@Character@@QEAAPEAVCampaignInstance@@XZ endp

; Character::wantsToTriggerCampaigns();
?wantsToTriggerCampaigns@Character@@QEAA_NXZ proc
jmp function_pointers[126*8]
?wantsToTriggerCampaigns@Character@@QEAA_NXZ endp

; Character::isUnique();
?isUnique@Character@@QEAA_NXZ proc
jmp function_pointers[127*8]
?isUnique@Character@@QEAA_NXZ endp

; Character::canSpeakNormally();
?canSpeakNormally@Character@@QEAA_NXZ proc
jmp function_pointers[128*8]
?canSpeakNormally@Character@@QEAA_NXZ endp

?_NV_isAnimal@Character@@QEAAPEAVCharacterAnimal@@XZ proc
?_NV_isAnimal@Character@@QEAAPEAVCharacterAnimal@@XZ endp

; Character::isAnimal();
?isAnimal@Character@@UEAAPEAVCharacterAnimal@@XZ proc
jmp function_pointers[129*8]
?isAnimal@Character@@UEAAPEAVCharacterAnimal@@XZ endp

?_NV_isHuman@Character@@QEAAPEAVCharacterHuman@@XZ proc
?_NV_isHuman@Character@@QEAAPEAVCharacterHuman@@XZ endp

; Character::isHuman();
?isHuman@Character@@UEAAPEAVCharacterHuman@@XZ proc
jmp function_pointers[130*8]
?isHuman@Character@@UEAAPEAVCharacterHuman@@XZ endp

?_NV_takeMoney@Character@@QEAA_NH@Z proc
?_NV_takeMoney@Character@@QEAA_NH@Z endp

; Character::takeMoney(int);
?takeMoney@Character@@UEAA_NH@Z proc
jmp function_pointers[131*8]
?takeMoney@Character@@UEAA_NH@Z endp

?_NV_getMoney@Character@@QEBAHXZ proc
?_NV_getMoney@Character@@QEBAHXZ endp

; Character::getMoney();
?getMoney@Character@@UEBAHXZ proc
jmp function_pointers[132*8]
?getMoney@Character@@UEBAHXZ endp

; Character::setSquadMemberType(enum SquadMemberType);
?setSquadMemberType@Character@@QEAAXW4SquadMemberType@@@Z proc
jmp function_pointers[133*8]
?setSquadMemberType@Character@@QEAAXW4SquadMemberType@@@Z endp

; Character::isResident();
?isResident@Character@@QEBAPEAVTownBase@@XZ proc
jmp function_pointers[134*8]
?isResident@Character@@QEBAPEAVTownBase@@XZ endp

; Character::dailyUpdate();
?dailyUpdate@Character@@QEAAXXZ proc
jmp function_pointers[135*8]
?dailyUpdate@Character@@QEAAXXZ endp

; Character::updateOnScreenCheck();
?updateOnScreenCheck@Character@@QEAA_NXZ proc
jmp function_pointers[136*8]
?updateOnScreenCheck@Character@@QEAA_NXZ endp

; Character::offscreenUpdate();
?offscreenUpdate@Character@@QEAAXXZ proc
jmp function_pointers[137*8]
?offscreenUpdate@Character@@QEAAXXZ endp

; Character::updateTimes();
?updateTimes@Character@@QEAAXXZ proc
jmp function_pointers[138*8]
?updateTimes@Character@@QEAAXXZ endp

?_NV_getSensoryData@Character@@QEAAPEAVSensoryData@@XZ proc
?_NV_getSensoryData@Character@@QEAAPEAVSensoryData@@XZ endp

; Character::getSensoryData();
?getSensoryData@Character@@UEAAPEAVSensoryData@@XZ proc
jmp function_pointers[139*8]
?getSensoryData@Character@@UEAAPEAVSensoryData@@XZ endp

?_NV_getStateBroadcast@Character@@QEAAPEAVStateBroadcastData@@XZ proc
?_NV_getStateBroadcast@Character@@QEAAPEAVStateBroadcastData@@XZ endp

; Character::getStateBroadcast();
?getStateBroadcast@Character@@UEAAPEAVStateBroadcastData@@XZ proc
jmp function_pointers[140*8]
?getStateBroadcast@Character@@UEAAPEAVStateBroadcastData@@XZ endp

?_NV_getFormation@Character@@QEBAPEAVFormation@@XZ proc
?_NV_getFormation@Character@@QEBAPEAVFormation@@XZ endp

; Character::getFormation();
?getFormation@Character@@UEBAPEAVFormation@@XZ proc
jmp function_pointers[141*8]
?getFormation@Character@@UEBAPEAVFormation@@XZ endp

?_NV_getEnemyFormation@Character@@QEBAPEAVFormation@@XZ proc
?_NV_getEnemyFormation@Character@@QEBAPEAVFormation@@XZ endp

; Character::getEnemyFormation();
?getEnemyFormation@Character@@UEBAPEAVFormation@@XZ proc
jmp function_pointers[142*8]
?getEnemyFormation@Character@@UEBAPEAVFormation@@XZ endp

; Character::formationUpdateCallback(const class Ogre::Vector3 &, const class hand &, const class Ogre::Vector3 &, class Formation *);
?formationUpdateCallback@Character@@QEAAXAEBVVector3@Ogre@@AEBVhand@@0PEAVFormation@@@Z proc
jmp function_pointers[143*8]
?formationUpdateCallback@Character@@QEAAXAEBVVector3@Ogre@@AEBVhand@@0PEAVFormation@@@Z endp

; Character::AIDestinationIndoorOutdoorCheck(class RootObject *);
?AIDestinationIndoorOutdoorCheck@Character@@QEAA_NPEAVRootObject@@@Z proc
jmp function_pointers[144*8]
?AIDestinationIndoorOutdoorCheck@Character@@QEAA_NPEAVRootObject@@@Z endp

?_NV_setHandle@Character@@QEAAXAEBVhand@@@Z proc
?_NV_setHandle@Character@@QEAAXAEBVhand@@@Z endp

; Character::setHandle(const class hand &);
?setHandle@Character@@UEAAXAEBVhand@@@Z proc
jmp function_pointers[145*8]
?setHandle@Character@@UEAAXAEBVhand@@@Z endp

?_NV_update@Character@@QEAAXXZ proc
?_NV_update@Character@@QEAAXXZ endp

; Character::update();
?update@Character@@UEAAXXZ proc
jmp function_pointers[146*8]
?update@Character@@UEAAXXZ endp

?_NV_postUpdate@Character@@QEAAXXZ proc
?_NV_postUpdate@Character@@QEAAXXZ endp

; Character::postUpdate();
?postUpdate@Character@@UEAAXXZ proc
jmp function_pointers[147*8]
?postUpdate@Character@@UEAAXXZ endp

; Character::ragdollUpdatesUT();
?ragdollUpdatesUT@Character@@QEAAXXZ proc
jmp function_pointers[148*8]
?ragdollUpdatesUT@Character@@QEAAXXZ endp

; Character::fourFrameUpdate();
?fourFrameUpdate@Character@@QEAAXXZ proc
jmp function_pointers[149*8]
?fourFrameUpdate@Character@@QEAAXXZ endp

?_NV_periodicUpdate@Character@@QEAAXXZ proc
?_NV_periodicUpdate@Character@@QEAAXXZ endp

; Character::periodicUpdate();
?periodicUpdate@Character@@UEAAXXZ proc
jmp function_pointers[150*8]
?periodicUpdate@Character@@UEAAXXZ endp

?_NV_pausedUpdate@Character@@QEAAXXZ proc
?_NV_pausedUpdate@Character@@QEAAXXZ endp

; Character::pausedUpdate();
?pausedUpdate@Character@@UEAAXXZ proc
jmp function_pointers[151*8]
?pausedUpdate@Character@@UEAAXXZ endp

; Character::updateUT();
?updateUT@Character@@QEAAXXZ proc
jmp function_pointers[152*8]
?updateUT@Character@@QEAAXXZ endp

?_NV_threadedUpdate@Character@@QEAAXXZ proc
?_NV_threadedUpdate@Character@@QEAAXXZ endp

; Character::threadedUpdate();
?threadedUpdate@Character@@UEAAXXZ proc
jmp function_pointers[153*8]
?threadedUpdate@Character@@UEAAXXZ endp

?_NV_threadedUpdate4@Character@@QEAAXXZ proc
?_NV_threadedUpdate4@Character@@QEAAXXZ endp

; Character::threadedUpdate4();
?threadedUpdate4@Character@@UEAAXXZ proc
jmp function_pointers[154*8]
?threadedUpdate4@Character@@UEAAXXZ endp

?_NV_threadedUpdatePeriodic@Character@@QEAAXXZ proc
?_NV_threadedUpdatePeriodic@Character@@QEAAXXZ endp

; Character::threadedUpdatePeriodic();
?threadedUpdatePeriodic@Character@@UEAAXXZ proc
jmp function_pointers[155*8]
?threadedUpdatePeriodic@Character@@UEAAXXZ endp

; Character::pathExists(const class Ogre::Vector3 &);
?pathExists@Character@@QEAA_NAEBVVector3@Ogre@@@Z proc
jmp function_pointers[156*8]
?pathExists@Character@@QEAA_NAEBVVector3@Ogre@@@Z endp

?_NV_weatherUpdate@Character@@QEAAXM@Z proc
?_NV_weatherUpdate@Character@@QEAAXM@Z endp

; Character::weatherUpdate(float);
?weatherUpdate@Character@@UEAAXM@Z proc
jmp function_pointers[157*8]
?weatherUpdate@Character@@UEAAXM@Z endp

; Character::stealthUpdate(float);
?stealthUpdate@Character@@QEAAXM@Z proc
jmp function_pointers[158*8]
?stealthUpdate@Character@@QEAAXM@Z endp

; Character::lineOfSightCheck(class Character *);
?lineOfSightCheck@Character@@QEAAMPEAV1@@Z proc
jmp function_pointers[159*8]
?lineOfSightCheck@Character@@QEAAMPEAV1@@Z endp

; Character::getPerceptionMult();
?getPerceptionMult@Character@@QEAAMXZ proc
jmp function_pointers[160*8]
?getPerceptionMult@Character@@QEAAMXZ endp

; Character::isWithThePlayer();
?isWithThePlayer@Character@@QEAA_NXZ proc
jmp function_pointers[161*8]
?isWithThePlayer@Character@@QEAA_NXZ endp

; Character::notifyICanSeeYouSneaking(class Character *, class YesNoMaybe, float);
?notifyICanSeeYouSneaking@Character@@QEAAXPEAV1@VYesNoMaybe@@M@Z proc
jmp function_pointers[162*8]
?notifyICanSeeYouSneaking@Character@@QEAAXPEAV1@VYesNoMaybe@@M@Z endp

; Character::isItSafeToGetUp();
?isItSafeToGetUp@Character@@QEAA_NXZ proc
jmp function_pointers[163*8]
?isItSafeToGetUp@Character@@QEAA_NXZ endp

; Character::separateIntoMyOwnSquad(bool);
?separateIntoMyOwnSquad@Character@@QEAAPEAVPlatoon@@_N@Z proc
jmp function_pointers[164*8]
?separateIntoMyOwnSquad@Character@@QEAAPEAVPlatoon@@_N@Z endp

; Character::dropGearOnDeath(bool);
?dropGearOnDeath@Character@@QEAAX_N@Z proc
jmp function_pointers[165*8]
?dropGearOnDeath@Character@@QEAAX_N@Z endp

?_NV_isItOkForMeToLoot@Character@@QEAA_NPEAVRootObject@@PEAVItem@@@Z proc
?_NV_isItOkForMeToLoot@Character@@QEAA_NPEAVRootObject@@PEAVItem@@@Z endp

; Character::isItOkForMeToLoot(class RootObject *, class Item *);
?isItOkForMeToLoot@Character@@UEAA_NPEAVRootObject@@PEAVItem@@@Z proc
jmp function_pointers[166*8]
?isItOkForMeToLoot@Character@@UEAA_NPEAVRootObject@@PEAVItem@@@Z endp

?_NV_ImStealingDoYouNotice@Character@@QEAA_NPEAVRootObject@@PEAVItem@@@Z proc
?_NV_ImStealingDoYouNotice@Character@@QEAA_NPEAVRootObject@@PEAVItem@@@Z endp

; Character::ImStealingDoYouNotice(class RootObject *, class Item *);
?ImStealingDoYouNotice@Character@@UEAA_NPEAVRootObject@@PEAVItem@@@Z proc
jmp function_pointers[167*8]
?ImStealingDoYouNotice@Character@@UEAA_NPEAVRootObject@@PEAVItem@@@Z endp

; Character::getFencingSuccessChance(class Item *, class RootObject *);
?getFencingSuccessChance@Character@@QEAAMPEAVItem@@PEAVRootObject@@@Z proc
jmp function_pointers[168*8]
?getFencingSuccessChance@Character@@QEAAMPEAVItem@@PEAVRootObject@@@Z endp

?_NV_stolenGoodsDetectionCheck@Character@@QEAA_NPEAVItem@@PEAVRootObject@@@Z proc
?_NV_stolenGoodsDetectionCheck@Character@@QEAA_NPEAVItem@@PEAVRootObject@@@Z endp

; Character::stolenGoodsDetectionCheck(class Item *, class RootObject *);
?stolenGoodsDetectionCheck@Character@@UEAA_NPEAVItem@@PEAVRootObject@@@Z proc
jmp function_pointers[169*8]
?stolenGoodsDetectionCheck@Character@@UEAA_NPEAVItem@@PEAVRootObject@@@Z endp

?_NV_sellingUniformDetectionCheck@Character@@QEAA_NPEAVItem@@PEAV1@@Z proc
?_NV_sellingUniformDetectionCheck@Character@@QEAA_NPEAVItem@@PEAV1@@Z endp

; Character::sellingUniformDetectionCheck(class Item *, class Character *);
?sellingUniformDetectionCheck@Character@@UEAA_NPEAVItem@@PEAV1@@Z proc
jmp function_pointers[170*8]
?sellingUniformDetectionCheck@Character@@UEAA_NPEAVItem@@PEAV1@@Z endp

?_NV_smugglingTradeCheck@Character@@QEAA?AVYesNoMaybe@@PEAVItem@@PEAV1@@Z proc
?_NV_smugglingTradeCheck@Character@@QEAA?AVYesNoMaybe@@PEAVItem@@PEAV1@@Z endp

; Character::smugglingTradeCheck(class Item *, class Character *);
?smugglingTradeCheck@Character@@UEAA?AVYesNoMaybe@@PEAVItem@@PEAV1@@Z proc
jmp function_pointers[171*8]
?smugglingTradeCheck@Character@@UEAA?AVYesNoMaybe@@PEAVItem@@PEAV1@@Z endp

; Character::getStealingSuccessChance(class RootObject *, class Item *, class Character * *);
?getStealingSuccessChance@Character@@QEAAMPEAVRootObject@@PEAVItem@@PEAPEAV1@@Z proc
jmp function_pointers[172*8]
?getStealingSuccessChance@Character@@QEAAMPEAVRootObject@@PEAVItem@@PEAPEAV1@@Z endp

; Character::getCurrentWeatherAffectStatus();
?getCurrentWeatherAffectStatus@Character@@QEBA?AW4WeatherAffecting@@XZ proc
jmp function_pointers[173*8]
?getCurrentWeatherAffectStatus@Character@@QEBA?AW4WeatherAffecting@@XZ endp

; Character::getCurrentWeatherAffectStrength();
?getCurrentWeatherAffectStrength@Character@@QEBAMXZ proc
jmp function_pointers[174*8]
?getCurrentWeatherAffectStrength@Character@@QEBAMXZ endp

; Character::getWaterLevel();
?getWaterLevel@Character@@QEAA?AW4Enum@WaterState@@XZ proc
jmp function_pointers[175*8]
?getWaterLevel@Character@@QEAA?AW4Enum@WaterState@@XZ endp

; Character::setTerrainHeightPosition(float);
?setTerrainHeightPosition@Character@@QEAAXM@Z proc
jmp function_pointers[176*8]
?setTerrainHeightPosition@Character@@QEAAXM@Z endp

; Character::getTerrainHeightPosition();
?getTerrainHeightPosition@Character@@QEAAMXZ proc
jmp function_pointers[177*8]
?getTerrainHeightPosition@Character@@QEAAMXZ endp

; Character::setDisguiseMessage(enum Character::DisguiseGUIFeedback);
?setDisguiseMessage@Character@@QEAAXW4DisguiseGUIFeedback@1@@Z proc
jmp function_pointers[178*8]
?setDisguiseMessage@Character@@QEAAXW4DisguiseGUIFeedback@1@@Z endp

; Character::uniqueStateUpdate();
?uniqueStateUpdate@Character@@QEAAXXZ proc
jmp function_pointers[179*8]
?uniqueStateUpdate@Character@@QEAAXXZ endp

?_NV_foodUpdate@Character@@QEAAXXZ proc
?_NV_foodUpdate@Character@@QEAAXXZ endp

; Character::foodUpdate();
?foodUpdate@Character@@UEAAXXZ proc
jmp function_pointers[180*8]
?foodUpdate@Character@@UEAAXXZ endp

; Character::eatItem(class Item *, class Inventory *);
?eatItem@Character@@QEAA_NPEAVItem@@PEAVInventory@@@Z proc
jmp function_pointers[181*8]
?eatItem@Character@@QEAA_NPEAVItem@@PEAVInventory@@@Z endp

?_NV_serialise@Character@@QEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z proc
?_NV_serialise@Character@@QEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z endp

; Character::serialise(class GameDataContainer *, class GameData *, class PosRotPair *);
?serialise@Character@@UEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z proc
jmp function_pointers[182*8]
?serialise@Character@@UEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z endp

?_NV_loadFromSerialise@Character@@QEAAXPEAVGameSaveState@@@Z proc
?_NV_loadFromSerialise@Character@@QEAAXPEAVGameSaveState@@@Z endp

; Character::loadFromSerialise(class GameSaveState *);
?loadFromSerialise@Character@@UEAAXPEAVGameSaveState@@@Z proc
jmp function_pointers[183*8]
?loadFromSerialise@Character@@UEAAXPEAVGameSaveState@@@Z endp

?_NV_loadFromSerialisePostCreationStage@Character@@QEAAXPEAVGameSaveState@@@Z proc
?_NV_loadFromSerialisePostCreationStage@Character@@QEAAXPEAVGameSaveState@@@Z endp

; Character::loadFromSerialisePostCreationStage(class GameSaveState *);
?loadFromSerialisePostCreationStage@Character@@UEAAXPEAVGameSaveState@@@Z proc
jmp function_pointers[184*8]
?loadFromSerialisePostCreationStage@Character@@UEAAXPEAVGameSaveState@@@Z endp

?_NV_setupInventorySections@Character@@QEAA_NPEAVGameSaveState@@@Z proc
?_NV_setupInventorySections@Character@@QEAA_NPEAVGameSaveState@@@Z endp

; Character::setupInventorySections(class GameSaveState *);
?setupInventorySections@Character@@UEAA_NPEAVGameSaveState@@@Z proc
jmp function_pointers[185*8]
?setupInventorySections@Character@@UEAA_NPEAVGameSaveState@@@Z endp

?_NV_getPosition@Character@@QEAA?AVVector3@Ogre@@XZ proc
?_NV_getPosition@Character@@QEAA?AVVector3@Ogre@@XZ endp

; Character::getPosition();
?getPosition@Character@@UEAA?AVVector3@Ogre@@XZ proc
jmp function_pointers[186*8]
?getPosition@Character@@UEAA?AVVector3@Ogre@@XZ endp

; Character::_getRawPosition();
?_getRawPosition@Character@@QEBA?AVVector3@Ogre@@XZ proc
jmp function_pointers[187*8]
?_getRawPosition@Character@@QEBA?AVVector3@Ogre@@XZ endp

; Character::getRawEntityPosition();
?getRawEntityPosition@Character@@QEAA?AVVector3@Ogre@@XZ proc
jmp function_pointers[188*8]
?getRawEntityPosition@Character@@QEAA?AVVector3@Ogre@@XZ endp

?_NV_getMovementSpeed@Character@@QEBAMXZ proc
?_NV_getMovementSpeed@Character@@QEBAMXZ endp

; Character::getMovementSpeed();
?getMovementSpeed@Character@@UEBAMXZ proc
jmp function_pointers[189*8]
?getMovementSpeed@Character@@UEBAMXZ endp

?_NV_getMovementSpeedOrders@Character@@QEBA?AW4MoveSpeed@@XZ proc
?_NV_getMovementSpeedOrders@Character@@QEBA?AW4MoveSpeed@@XZ endp

; Character::getMovementSpeedOrders();
?getMovementSpeedOrders@Character@@UEBA?AW4MoveSpeed@@XZ proc
jmp function_pointers[190*8]
?getMovementSpeedOrders@Character@@UEBA?AW4MoveSpeed@@XZ endp

?_NV_getMovementDirection@Character@@QEBA?AVVector3@Ogre@@XZ proc
?_NV_getMovementDirection@Character@@QEBA?AVVector3@Ogre@@XZ endp

; Character::getMovementDirection();
?getMovementDirection@Character@@UEBA?AVVector3@Ogre@@XZ proc
jmp function_pointers[191*8]
?getMovementDirection@Character@@UEBA?AVVector3@Ogre@@XZ endp

?_NV_isPhysical@Character@@QEBA_NXZ proc
?_NV_isPhysical@Character@@QEBA_NXZ endp

; Character::isPhysical();
?isPhysical@Character@@UEBA_NXZ proc
jmp function_pointers[192*8]
?isPhysical@Character@@UEBA_NXZ endp

?_NV_setVisible@Character@@QEAAX_N@Z proc
?_NV_setVisible@Character@@QEAAX_N@Z endp

; Character::setVisible(bool);
?setVisible@Character@@UEAAX_N@Z proc
jmp function_pointers[193*8]
?setVisible@Character@@UEAAX_N@Z endp

?_NV_getVisible@Character@@QEBA_NXZ proc
?_NV_getVisible@Character@@QEBA_NXZ endp

; Character::getVisible();
?getVisible@Character@@UEBA_NXZ proc
jmp function_pointers[194*8]
?getVisible@Character@@UEBA_NXZ endp

; Character::switchLights(bool);
?switchLights@Character@@QEAAX_N@Z proc
jmp function_pointers[195*8]
?switchLights@Character@@QEAAX_N@Z endp

?_NV_isDisabled@Character@@QEAA_NXZ proc
?_NV_isDisabled@Character@@QEAA_NXZ endp

; Character::isDisabled();
?isDisabled@Character@@UEAA_NXZ proc
jmp function_pointers[196*8]
?isDisabled@Character@@UEAA_NXZ endp

?_NV_setInsideTownWalls@Character@@QEAAXH@Z proc
?_NV_setInsideTownWalls@Character@@QEAAXH@Z endp

; Character::setInsideTownWalls(int);
?setInsideTownWalls@Character@@UEAAXH@Z proc
jmp function_pointers[197*8]
?setInsideTownWalls@Character@@UEAAXH@Z endp

?_NV_sheatheWeapon@Character@@QEAAXXZ proc
?_NV_sheatheWeapon@Character@@QEAAXXZ endp

; Character::sheatheWeapon();
?sheatheWeapon@Character@@UEAAXXZ proc
jmp function_pointers[198*8]
?sheatheWeapon@Character@@UEAAXXZ endp

?_NV_select@Character@@QEAAXXZ proc
?_NV_select@Character@@QEAAXXZ endp

; Character::select();
?select@Character@@UEAAXXZ proc
jmp function_pointers[199*8]
?select@Character@@UEAAXXZ endp

?_NV_unselect@Character@@QEAAXXZ proc
?_NV_unselect@Character@@QEAAXXZ endp

; Character::unselect();
?unselect@Character@@UEAAXXZ proc
jmp function_pointers[200*8]
?unselect@Character@@UEAAXXZ endp

?_NV_getGUIData@Character@@QEAAXPEAVDatapanelGUI@@H@Z proc
?_NV_getGUIData@Character@@QEAAXPEAVDatapanelGUI@@H@Z endp

; Character::getGUIData(class DatapanelGUI *, int);
?getGUIData@Character@@UEAAXPEAVDatapanelGUI@@H@Z proc
jmp function_pointers[201*8]
?getGUIData@Character@@UEAAXPEAVDatapanelGUI@@H@Z endp

?_NV_getCurrentTownLocation@Character@@QEAAPEAVTownBase@@XZ proc
?_NV_getCurrentTownLocation@Character@@QEAAPEAVTownBase@@XZ endp

; Character::getCurrentTownLocation();
?getCurrentTownLocation@Character@@UEAAPEAVTownBase@@XZ proc
jmp function_pointers[202*8]
?getCurrentTownLocation@Character@@UEAAPEAVTownBase@@XZ endp

?_NV_say_WithARepeatLimiter@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_say_WithARepeatLimiter@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; Character::say_WithARepeatLimiter(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?say_WithARepeatLimiter@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[203*8]
?say_WithARepeatLimiter@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_say@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_say@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; Character::say(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?say@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[204*8]
?say@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_isInventoryVisible@Character@@QEBA_NXZ proc
?_NV_isInventoryVisible@Character@@QEBA_NXZ endp

; Character::isInventoryVisible();
?isInventoryVisible@Character@@UEBA_NXZ proc
jmp function_pointers[205*8]
?isInventoryVisible@Character@@UEBA_NXZ endp

?_NV_giveItem@Character@@QEAA_NPEAVItem@@_N1@Z proc
?_NV_giveItem@Character@@QEAA_NPEAVItem@@_N1@Z endp

; Character::giveItem(class Item *, bool, bool);
?giveItem@Character@@UEAA_NPEAVItem@@_N1@Z proc
jmp function_pointers[206*8]
?giveItem@Character@@UEAA_NPEAVItem@@_N1@Z endp

?_NV_hasRoomForItem@Character@@QEAA_NPEAVGameData@@@Z proc
?_NV_hasRoomForItem@Character@@QEAA_NPEAVGameData@@@Z endp

; Character::hasRoomForItem(class GameData *);
?hasRoomForItem@Character@@UEAA_NPEAVGameData@@@Z proc
jmp function_pointers[207*8]
?hasRoomForItem@Character@@UEAA_NPEAVGameData@@@Z endp

?_NV_hasItem@Character@@QEAA_NPEAVGameData@@@Z proc
?_NV_hasItem@Character@@QEAA_NPEAVGameData@@@Z endp

; Character::hasItem(class GameData *);
?hasItem@Character@@UEAA_NPEAVGameData@@@Z proc
jmp function_pointers[208*8]
?hasItem@Character@@UEAA_NPEAVGameData@@@Z endp

?_NV_hasAmmoFor@Character@@QEAA_NPEAVCrossbow@@@Z proc
?_NV_hasAmmoFor@Character@@QEAA_NPEAVCrossbow@@@Z endp

; Character::hasAmmoFor(class Crossbow *);
?hasAmmoFor@Character@@UEAA_NPEAVCrossbow@@@Z proc
jmp function_pointers[209*8]
?hasAmmoFor@Character@@UEAA_NPEAVCrossbow@@@Z endp

?_NV_getNumFoodItems@Character@@QEAAHXZ proc
?_NV_getNumFoodItems@Character@@QEAAHXZ endp

; Character::getNumFoodItems();
?getNumFoodItems@Character@@UEAAHXZ proc
jmp function_pointers[210*8]
?getNumFoodItems@Character@@UEAAHXZ endp

?_NV_hasSimilarItem@Character@@QEAA_NW4itemType@@@Z proc
?_NV_hasSimilarItem@Character@@QEAA_NW4itemType@@@Z endp

; Character::hasSimilarItem(enum itemType);
?hasSimilarItem@Character@@UEAA_NW4itemType@@@Z proc
jmp function_pointers[211*8]
?hasSimilarItem@Character@@UEAA_NW4itemType@@@Z endp

; Character::ifImASmithShouldIDitchMyBackWeapon();
?ifImASmithShouldIDitchMyBackWeapon@Character@@QEAA_NXZ proc
jmp function_pointers[212*8]
?ifImASmithShouldIDitchMyBackWeapon@Character@@QEAA_NXZ endp

?_NV_hasItemsFrom@Character@@QEAA_NPEAVStorageBuilding@@AEAV?$unordered_set@PEAVGameData@@U?$hash@PEAVGameData@@@boost@@U?$equal_to@PEAVGameData@@@std@@V?$STLAllocator@PEAVGameData@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@@Z proc
?_NV_hasItemsFrom@Character@@QEAA_NPEAVStorageBuilding@@AEAV?$unordered_set@PEAVGameData@@U?$hash@PEAVGameData@@@boost@@U?$equal_to@PEAVGameData@@@std@@V?$STLAllocator@PEAVGameData@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@@Z endp

; Character::hasItemsFrom(class StorageBuilding *, class boost::unordered::unordered_set<GameData *,boost::hash<GameData *>,std::equal_to<GameData *>,Ogre::STLAllocator<GameData *,Ogre::CategorisedAllocPolicy<0> > > &);
?hasItemsFrom@Character@@UEAA_NPEAVStorageBuilding@@AEAV?$unordered_set@PEAVGameData@@U?$hash@PEAVGameData@@@boost@@U?$equal_to@PEAVGameData@@@std@@V?$STLAllocator@PEAVGameData@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@@Z proc
jmp function_pointers[213*8]
?hasItemsFrom@Character@@UEAA_NPEAVStorageBuilding@@AEAV?$unordered_set@PEAVGameData@@U?$hash@PEAVGameData@@@boost@@U?$equal_to@PEAVGameData@@@std@@V?$STLAllocator@PEAVGameData@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@@Z endp

?_NV_getInventory@Character@@QEBAPEAVInventory@@XZ proc
?_NV_getInventory@Character@@QEBAPEAVInventory@@XZ endp

; Character::getInventory();
?getInventory@Character@@UEBAPEAVInventory@@XZ proc
jmp function_pointers[214*8]
?getInventory@Character@@UEBAPEAVInventory@@XZ endp

; Character::hasABackpackOn();
?hasABackpackOn@Character@@QEBAPEAVContainerItem@@XZ proc
jmp function_pointers[215*8]
?hasABackpackOn@Character@@QEBAPEAVContainerItem@@XZ endp

; Character::isATrader();
?isATrader@Character@@QEBA_NXZ proc
jmp function_pointers[216*8]
?isATrader@Character@@QEBA_NXZ endp

; Character::isFemale();
?isFemale@Character@@QEAA_NXZ proc
jmp function_pointers[217*8]
?isFemale@Character@@QEAA_NXZ endp

; Character::isFleeing();
?isFleeing@Character@@QEAA_NXZ proc
jmp function_pointers[218*8]
?isFleeing@Character@@QEAA_NXZ endp

?_NV_createInventoryLayout@Character@@QEAAPEAVInventoryLayout@@XZ proc
?_NV_createInventoryLayout@Character@@QEAAPEAVInventoryLayout@@XZ endp

; Character::createInventoryLayout();
?createInventoryLayout@Character@@UEAAPEAVInventoryLayout@@XZ proc
jmp function_pointers[219*8]
?createInventoryLayout@Character@@UEAAPEAVInventoryLayout@@XZ endp

; Character::getStealthKOChance(class Character *, bool);
?getStealthKOChance@Character@@QEAAMPEAV1@_N@Z proc
jmp function_pointers[220*8]
?getStealthKOChance@Character@@QEAAMPEAV1@_N@Z endp

; Character::getKidnappingChance(class Character *);
?getKidnappingChance@Character@@QEAAMPEAV1@@Z proc
jmp function_pointers[221*8]
?getKidnappingChance@Character@@QEAAMPEAV1@@Z endp

; Character::getKidnappingEscapeChance_skill(class Character *);
?getKidnappingEscapeChance_skill@Character@@QEAAMPEAV1@@Z proc
jmp function_pointers[222*8]
?getKidnappingEscapeChance_skill@Character@@QEAAMPEAV1@@Z endp

; Character::getKidnappingEscapeChance_strength(class Character *);
?getKidnappingEscapeChance_strength@Character@@QEAAMPEAV1@@Z proc
jmp function_pointers[223*8]
?getKidnappingEscapeChance_strength@Character@@QEAAMPEAV1@@Z endp

; Character::getLockpickChance(class DoorLock *);
?getLockpickChance@Character@@QEAAMPEAVDoorLock@@@Z proc
jmp function_pointers[224*8]
?getLockpickChance@Character@@QEAAMPEAVDoorLock@@@Z endp

; Character::shouldIHelpThisGuy(class Character *);
?shouldIHelpThisGuy@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[225*8]
?shouldIHelpThisGuy@Character@@QEAA_NPEAV1@@Z endp

; Character::shouldIScrewThisGuyOver(class Character *);
?shouldIScrewThisGuyOver@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[226*8]
?shouldIScrewThisGuyOver@Character@@QEAA_NPEAV1@@Z endp

; Character::ILoveThisGuyBecauseOfStuffThatHappened(class Character *);
?ILoveThisGuyBecauseOfStuffThatHappened@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[227*8]
?ILoveThisGuyBecauseOfStuffThatHappened@Character@@QEAA_NPEAV1@@Z endp

; Character::IHateThisGuyBecauseOfStuffThatHappened(class Character *);
?IHateThisGuyBecauseOfStuffThatHappened@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[228*8]
?IHateThisGuyBecauseOfStuffThatHappened@Character@@QEAA_NPEAV1@@Z endp

; Character::getRoughLevel();
?getRoughLevel@Character@@QEAAHXZ proc
jmp function_pointers[229*8]
?getRoughLevel@Character@@QEAAHXZ endp

?_NV_setStandingOrder@Character@@QEAAXW4StandingOrder@MessageForB@@_N@Z proc
?_NV_setStandingOrder@Character@@QEAAXW4StandingOrder@MessageForB@@_N@Z endp

; Character::setStandingOrder(enum MessageForB::StandingOrder, bool);
?setStandingOrder@Character@@UEAAXW4StandingOrder@MessageForB@@_N@Z proc
jmp function_pointers[230*8]
?setStandingOrder@Character@@UEAAXW4StandingOrder@MessageForB@@_N@Z endp

; Character::getStandingOrder(enum MessageForB::StandingOrder);
?getStandingOrder@Character@@QEBA_NW4StandingOrder@MessageForB@@@Z proc
jmp function_pointers[231*8]
?getStandingOrder@Character@@QEBA_NW4StandingOrder@MessageForB@@@Z endp

; Character::setStealthMode(bool);
?setStealthMode@Character@@QEAAX_N@Z proc
jmp function_pointers[232*8]
?setStealthMode@Character@@QEAAX_N@Z endp

; Character::isStealthMode();
?isStealthMode@Character@@QEBA_NXZ proc
jmp function_pointers[233*8]
?isStealthMode@Character@@QEBA_NXZ endp

; Character::isStealthModeOrCrawling();
?isStealthModeOrCrawling@Character@@QEBA_NXZ proc
jmp function_pointers[234*8]
?isStealthModeOrCrawling@Character@@QEBA_NXZ endp

; Character::declareDead();
?declareDead@Character@@QEAAXXZ proc
jmp function_pointers[235*8]
?declareDead@Character@@QEAAXXZ endp

; Character::updateGUIStatsDetails(class DatapanelGUI *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, int);
?updateGUIStatsDetails@Character@@QEAAXPEAVDatapanelGUI@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z proc
jmp function_pointers[236*8]
?updateGUIStatsDetails@Character@@QEAAXPEAVDatapanelGUI@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z endp

; Character::_printRaceXPBonusLine(class DatapanelGUI *, enum StatsEnumerated);
?_printRaceXPBonusLine@Character@@QEAAXPEAVDatapanelGUI@@W4StatsEnumerated@@@Z proc
jmp function_pointers[237*8]
?_printRaceXPBonusLine@Character@@QEAAXPEAVDatapanelGUI@@W4StatsEnumerated@@@Z endp

; Character::addGoal(enum TaskType, class RootObjectBase *);
?addGoal@Character@@QEAAXW4TaskType@@PEAVRootObjectBase@@@Z proc
jmp function_pointers[238*8]
?addGoal@Character@@QEAAXW4TaskType@@PEAVRootObjectBase@@@Z endp

; Character::addJob(enum TaskType, class RootObject *, bool, bool, const class Ogre::Vector3 &);
?addJob@Character@@QEAAXW4TaskType@@PEAVRootObject@@_N2AEBVVector3@Ogre@@@Z proc
jmp function_pointers[239*8]
?addJob@Character@@QEAAXW4TaskType@@PEAVRootObject@@_N2AEBVVector3@Ogre@@@Z endp

; Character::removeJob(enum TaskType);
?removeJob@Character@@QEAAXW4TaskType@@@Z proc
jmp function_pointers[240*8]
?removeJob@Character@@QEAAXW4TaskType@@@Z endp

; Character::removePermajob(int);
?removePermajob@Character@@QEAAXH@Z proc
jmp function_pointers[241*8]
?removePermajob@Character@@QEAAXH@Z endp

; Character::clearPermajobs();
?clearPermajobs@Character@@QEAAXXZ proc
jmp function_pointers[242*8]
?clearPermajobs@Character@@QEAAXXZ endp

; Character::movePermajob(int, int);
?movePermajob@Character@@QEAAXHH@Z proc
jmp function_pointers[243*8]
?movePermajob@Character@@QEAAXHH@Z endp

; Character::getPermajobName(int);
?getPermajobName@Character@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z proc
jmp function_pointers[244*8]
?getPermajobName@Character@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z endp

; Character::getPermajob(int);
?getPermajob@Character@@QEBA?AW4TaskType@@H@Z proc
jmp function_pointers[245*8]
?getPermajob@Character@@QEBA?AW4TaskType@@H@Z endp

; Character::getPermajobData(int);
?getPermajobData@Character@@QEBAPEBVTasker@@H@Z proc
jmp function_pointers[246*8]
?getPermajobData@Character@@QEBAPEBVTasker@@H@Z endp

; Character::getPermajobCount();
?getPermajobCount@Character@@QEBAHXZ proc
jmp function_pointers[247*8]
?getPermajobCount@Character@@QEBAHXZ endp

?_NV_getAABB@Character@@QEBAAEBUAabb@Ogre@@XZ proc
?_NV_getAABB@Character@@QEBAAEBUAabb@Ogre@@XZ endp

; Character::getAABB();
?getAABB@Character@@UEBAAEBUAabb@Ogre@@XZ proc
jmp function_pointers[248*8]
?getAABB@Character@@UEBAAEBUAabb@Ogre@@XZ endp

; Character::addOrder(class Building *, enum TaskType, class RootObject *, bool, bool, const class Ogre::Vector3 &);
?addOrder@Character@@QEAAXPEAVBuilding@@W4TaskType@@PEAVRootObject@@_N3AEBVVector3@Ogre@@@Z proc
jmp function_pointers[249*8]
?addOrder@Character@@QEAAXPEAVBuilding@@W4TaskType@@PEAVRootObject@@_N3AEBVVector3@Ogre@@@Z endp

?_NV_updateLastTask@Character@@QEAAXPEAVBuilding@@W4TaskType@@PEAVRootObject@@AEBVVector3@Ogre@@@Z proc
?_NV_updateLastTask@Character@@QEAAXPEAVBuilding@@W4TaskType@@PEAVRootObject@@AEBVVector3@Ogre@@@Z endp

; Character::updateLastTask(class Building *, enum TaskType, class RootObject *, const class Ogre::Vector3 &);
?updateLastTask@Character@@UEAAXPEAVBuilding@@W4TaskType@@PEAVRootObject@@AEBVVector3@Ogre@@@Z proc
jmp function_pointers[250*8]
?updateLastTask@Character@@UEAAXPEAVBuilding@@W4TaskType@@PEAVRootObject@@AEBVVector3@Ogre@@@Z endp

?_NV_playerMoveOrderDefault@Character@@QEAAXPEAVBuilding@@PEAVRootObject@@AEBVVector3@Ogre@@@Z proc
?_NV_playerMoveOrderDefault@Character@@QEAAXPEAVBuilding@@PEAVRootObject@@AEBVVector3@Ogre@@@Z endp

; Character::playerMoveOrderDefault(class Building *, class RootObject *, const class Ogre::Vector3 &);
?playerMoveOrderDefault@Character@@UEAAXPEAVBuilding@@PEAVRootObject@@AEBVVector3@Ogre@@@Z proc
jmp function_pointers[251*8]
?playerMoveOrderDefault@Character@@UEAAXPEAVBuilding@@PEAVRootObject@@AEBVVector3@Ogre@@@Z endp

; Character::endCombatMode();
?endCombatMode@Character@@QEAAXXZ proc
jmp function_pointers[252*8]
?endCombatMode@Character@@QEAAXXZ endp

?_NV_getTotalRelativeStrengthOfAttackers@Character@@QEAAMXZ proc
?_NV_getTotalRelativeStrengthOfAttackers@Character@@QEAAMXZ endp

; Character::getTotalRelativeStrengthOfAttackers();
?getTotalRelativeStrengthOfAttackers@Character@@UEAAMXZ proc
jmp function_pointers[253*8]
?getTotalRelativeStrengthOfAttackers@Character@@UEAAMXZ endp

?_NV_canGoIndoors@Character@@QEBA_NPEAVBuilding@@@Z proc
?_NV_canGoIndoors@Character@@QEBA_NPEAVBuilding@@@Z endp

; Character::canGoIndoors(class Building *);
?canGoIndoors@Character@@UEBA_NPEAVBuilding@@@Z proc
jmp function_pointers[254*8]
?canGoIndoors@Character@@UEBA_NPEAVBuilding@@@Z endp

?_NV_isIndoors@Character@@QEBAAEBVhand@@XZ proc
?_NV_isIndoors@Character@@QEBAAEBVhand@@XZ endp

; Character::isIndoors();
?isIndoors@Character@@UEBAAEBVhand@@XZ proc
jmp function_pointers[255*8]
?isIndoors@Character@@UEBAAEBVhand@@XZ endp

?_NV_isStandingOnBuilding@Character@@QEBAAEBVhand@@XZ proc
?_NV_isStandingOnBuilding@Character@@QEBAAEBVhand@@XZ endp

; Character::isStandingOnBuilding();
?isStandingOnBuilding@Character@@UEBAAEBVhand@@XZ proc
jmp function_pointers[256*8]
?isStandingOnBuilding@Character@@UEBAAEBVhand@@XZ endp

?_NV_isIndoorsRagdoll@Character@@QEBA_NXZ proc
?_NV_isIndoorsRagdoll@Character@@QEBA_NXZ endp

; Character::isIndoorsRagdoll();
?isIndoorsRagdoll@Character@@UEBA_NXZ proc
jmp function_pointers[257*8]
?isIndoorsRagdoll@Character@@UEBA_NXZ endp

?_NV_notifyIndoors@Character@@QEAAXAEBVhand@@@Z proc
?_NV_notifyIndoors@Character@@QEAAXAEBVhand@@@Z endp

; Character::notifyIndoors(const class hand &);
?notifyIndoors@Character@@UEAAXAEBVhand@@@Z proc
jmp function_pointers[258*8]
?notifyIndoors@Character@@UEAAXAEBVhand@@@Z endp

; Character::destinationIndoors(class RootObject *);
?destinationIndoors@Character@@QEBA?AVhand@@PEAVRootObject@@@Z proc
jmp function_pointers[259*8]
?destinationIndoors@Character@@QEBA?AVhand@@PEAVRootObject@@@Z endp

; Character::destinationInsideWalls(class RootObject *);
?destinationInsideWalls@Character@@QEAAHPEAVRootObject@@@Z proc
jmp function_pointers[260*8]
?destinationInsideWalls@Character@@QEAAHPEAVRootObject@@@Z endp

; Character::setDestinationIndoors(const class hand &);
?setDestinationIndoors@Character@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[261*8]
?setDestinationIndoors@Character@@QEAAXAEBVhand@@@Z endp

?_NV_getIntendedAggression@Character@@QEAAMXZ proc
?_NV_getIntendedAggression@Character@@QEAAMXZ endp

; Character::getIntendedAggression();
?getIntendedAggression@Character@@UEAAMXZ proc
jmp function_pointers[262*8]
?getIntendedAggression@Character@@UEAAMXZ endp

; Character::getPositionBip01();
?getPositionBip01@Character@@QEAA?AVVector3@Ogre@@XZ proc
jmp function_pointers[263*8]
?getPositionBip01@Character@@QEAA?AVVector3@Ogre@@XZ endp

?_NV_amInsideTownWalls@Character@@QEAAHXZ proc
?_NV_amInsideTownWalls@Character@@QEAAHXZ endp

; Character::amInsideTownWalls();
?amInsideTownWalls@Character@@UEAAHXZ proc
jmp function_pointers[264*8]
?amInsideTownWalls@Character@@UEAAHXZ endp

?_NV_setName@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_setName@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; Character::setName(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?setName@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[265*8]
?setName@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; Character::setNameTagVisible(bool);
?setNameTagVisible@Character@@QEAAX_N@Z proc
jmp function_pointers[266*8]
?setNameTagVisible@Character@@QEAAX_N@Z endp

; Character::ragdollMode(bool, enum RagdollPart::Enum);
?ragdollMode@Character@@QEAAX_NW4Enum@RagdollPart@@@Z proc
jmp function_pointers[267*8]
?ragdollMode@Character@@QEAAX_NW4Enum@RagdollPart@@@Z endp

; Character::isRagdoll();
?isRagdoll@Character@@QEBA_NXZ proc
jmp function_pointers[268*8]
?isRagdoll@Character@@QEBA_NXZ endp

; Character::isDown();
?isDown@Character@@QEAA_NXZ proc
jmp function_pointers[269*8]
?isDown@Character@@QEAA_NXZ endp

; Character::getRagdollPhysicsRootPos();
?getRagdollPhysicsRootPos@Character@@QEAA?AVVector3@Ogre@@XZ proc
jmp function_pointers[270*8]
?getRagdollPhysicsRootPos@Character@@QEAA?AVVector3@Ogre@@XZ endp

?_NV_amSomeoneWhoNeedsToEatToLive@Character@@QEAA_NXZ proc
?_NV_amSomeoneWhoNeedsToEatToLive@Character@@QEAA_NXZ endp

; Character::amSomeoneWhoNeedsToEatToLive();
?amSomeoneWhoNeedsToEatToLive@Character@@UEAA_NXZ proc
jmp function_pointers[271*8]
?amSomeoneWhoNeedsToEatToLive@Character@@UEAA_NXZ endp

?_NV_getMagicHungerSetting@Character@@QEAAMXZ proc
?_NV_getMagicHungerSetting@Character@@QEAAMXZ endp

; Character::getMagicHungerSetting();
?getMagicHungerSetting@Character@@UEAAMXZ proc
jmp function_pointers[272*8]
?getMagicHungerSetting@Character@@UEAAMXZ endp

; Character::wantsToEatNow();
?wantsToEatNow@Character@@QEAA_NXZ proc
jmp function_pointers[273*8]
?wantsToEatNow@Character@@QEAA_NXZ endp

?_NV_isKidnapped@Character@@QEAA_NXZ proc
?_NV_isKidnapped@Character@@QEAA_NXZ endp

; Character::isKidnapped();
?isKidnapped@Character@@UEAA_NXZ proc
jmp function_pointers[274*8]
?isKidnapped@Character@@UEAA_NXZ endp

?_NV_isLiterallyUnconciousNotPretending@Character@@QEBA_NXZ proc
?_NV_isLiterallyUnconciousNotPretending@Character@@QEBA_NXZ endp

; Character::isLiterallyUnconciousNotPretending();
?isLiterallyUnconciousNotPretending@Character@@UEBA_NXZ proc
jmp function_pointers[275*8]
?isLiterallyUnconciousNotPretending@Character@@UEBA_NXZ endp

?_NV_isUnconcious@Character@@QEBA_NXZ proc
?_NV_isUnconcious@Character@@QEBA_NXZ endp

; Character::isUnconcious();
?isUnconcious@Character@@UEBA_NXZ proc
jmp function_pointers[276*8]
?isUnconcious@Character@@UEBA_NXZ endp

?_NV_isCrippled@Character@@QEBA_NXZ proc
?_NV_isCrippled@Character@@QEBA_NXZ endp

; Character::isCrippled();
?isCrippled@Character@@UEBA_NXZ proc
jmp function_pointers[277*8]
?isCrippled@Character@@UEBA_NXZ endp

?_NV_getProneState@Character@@QEBA?AW4ProneState@@XZ proc
?_NV_getProneState@Character@@QEBA?AW4ProneState@@XZ endp

; Character::getProneState();
?getProneState@Character@@UEBA?AW4ProneState@@XZ proc
jmp function_pointers[278*8]
?getProneState@Character@@UEBA?AW4ProneState@@XZ endp

?_NV_setProneState@Character@@QEAAXW4ProneState@@@Z proc
?_NV_setProneState@Character@@QEAAXW4ProneState@@@Z endp

; Character::setProneState(enum ProneState);
?setProneState@Character@@UEAAXW4ProneState@@@Z proc
jmp function_pointers[279*8]
?setProneState@Character@@UEAAXW4ProneState@@@Z endp

; Character::_killRagdoll(bool);
?_killRagdoll@Character@@QEAAX_N@Z proc
jmp function_pointers[280*8]
?_killRagdoll@Character@@QEAAX_N@Z endp

?_NV_giveBirth@Character@@QEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z proc
?_NV_giveBirth@Character@@QEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z endp

; Character::giveBirth(class GameDataCopyStandalone *, const class Ogre::Vector3 &, const class Ogre::Quaternion &, class GameSaveState *, class ActivePlatoon *, class Faction *);
?giveBirth@Character@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z proc
jmp function_pointers[281*8]
?giveBirth@Character@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z endp

; Character::setupAI();
?setupAI@Character@@QEAAXXZ proc
jmp function_pointers[282*8]
?setupAI@Character@@QEAAXXZ endp

; Character::clearAllAIGoals();
?clearAllAIGoals@Character@@QEAAXXZ proc
jmp function_pointers[283*8]
?clearAllAIGoals@Character@@QEAAXXZ endp

; Character::setupPlatoonAI();
?setupPlatoonAI@Character@@QEAAXXZ proc
jmp function_pointers[284*8]
?setupPlatoonAI@Character@@QEAAXXZ endp

; Character::setAppearanceData(class GameDataCopyStandalone *);
?setAppearanceData@Character@@QEAAXPEAVGameDataCopyStandalone@@@Z proc
jmp function_pointers[285*8]
?setAppearanceData@Character@@QEAAXPEAVGameDataCopyStandalone@@@Z endp

; Character::getAppearanceData();
?getAppearanceData@Character@@QEAAPEAVGameDataCopyStandalone@@XZ proc
jmp function_pointers[286*8]
?getAppearanceData@Character@@QEAAPEAVGameDataCopyStandalone@@XZ endp

; Character::setDestination(const class Ogre::Vector3 &, bool);
?setDestination@Character@@QEAAXAEBVVector3@Ogre@@_N@Z proc
jmp function_pointers[287*8]
?setDestination@Character@@QEAAXAEBVVector3@Ogre@@_N@Z endp

; Character::sendDialogEventOverride(class Character *, enum EventTriggerEnum, bool);
?sendDialogEventOverride@Character@@QEAA_NPEAV1@W4EventTriggerEnum@@_N@Z proc
jmp function_pointers[288*8]
?sendDialogEventOverride@Character@@QEAA_NPEAV1@W4EventTriggerEnum@@_N@Z endp

; Character::sendDialogEvent(class Character *, enum EventTriggerEnum);
?sendDialogEvent@Character@@QEAA_NPEAV1@W4EventTriggerEnum@@@Z proc
jmp function_pointers[289*8]
?sendDialogEvent@Character@@QEAA_NPEAV1@W4EventTriggerEnum@@@Z endp

; Character::sayALine(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?sayALine@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[290*8]
?sayALine@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; Character::hasDialogue();
?hasDialogue@Character@@QEBA_NXZ proc
jmp function_pointers[291*8]
?hasDialogue@Character@@QEBA_NXZ endp

; Character::willTalkToEnemies();
?willTalkToEnemies@Character@@QEAA_NXZ proc
jmp function_pointers[292*8]
?willTalkToEnemies@Character@@QEAA_NXZ endp

; Character::relocationTeleport(const class Ogre::Vector3 &);
?relocationTeleport@Character@@QEAAXAEBVVector3@Ogre@@@Z proc
jmp function_pointers[293*8]
?relocationTeleport@Character@@QEAAXAEBVVector3@Ogre@@@Z endp

; Character::teleport(const class Ogre::Vector3 &, const class Ogre::Quaternion &);
?teleport@Character@@QEAAXAEBVVector3@Ogre@@AEBVQuaternion@3@@Z proc
jmp function_pointers[294*8]
?teleport@Character@@QEAAXAEBVVector3@Ogre@@AEBVQuaternion@3@@Z endp

; Character::teleport(const class Ogre::Vector3 &);
?teleport@Character@@QEAAXAEBVVector3@Ogre@@@Z proc
jmp function_pointers[295*8]
?teleport@Character@@QEAAXAEBVVector3@Ogre@@@Z endp

; Character::teleportVisuallyOnly(const class Ogre::Vector3 &, const class Ogre::Quaternion &);
?teleportVisuallyOnly@Character@@QEAAXAEBVVector3@Ogre@@AEBVQuaternion@3@@Z proc
jmp function_pointers[296*8]
?teleportVisuallyOnly@Character@@QEAAXAEBVVector3@Ogre@@AEBVQuaternion@3@@Z endp

; Character::teleportFromAnimation();
?teleportFromAnimation@Character@@QEAAXXZ proc
jmp function_pointers[297*8]
?teleportFromAnimation@Character@@QEAAXXZ endp

; Character::debugIndicateCharacters(class lektor<Character *>);
?debugIndicateCharacters@Character@@QEAAXV?$lektor@PEAVCharacter@@@@@Z proc
jmp function_pointers[298*8]
?debugIndicateCharacters@Character@@QEAAXV?$lektor@PEAVCharacter@@@@@Z endp

; Character::attackTarget(class Character *);
?attackTarget@Character@@QEAAXPEAV1@@Z proc
jmp function_pointers[299*8]
?attackTarget@Character@@QEAAXPEAV1@@Z endp

; Character::notifyTheCampaignOfAnAttack(class Character *);
?notifyTheCampaignOfAnAttack@Character@@QEAAXPEAV1@@Z proc
jmp function_pointers[300*8]
?notifyTheCampaignOfAnAttack@Character@@QEAAXPEAV1@@Z endp

; Character::iShouldntAggravateThisTarget(class Character *);
?iShouldntAggravateThisTarget@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[301*8]
?iShouldntAggravateThisTarget@Character@@QEAA_NPEAV1@@Z endp

; Character::sendMessage(enum CharacterMessage, class RootObject *, class RootObject *);
?sendMessage@Character@@QEAAXW4CharacterMessage@@PEAVRootObject@@1@Z proc
jmp function_pointers[302*8]
?sendMessage@Character@@QEAAXW4CharacterMessage@@PEAVRootObject@@1@Z endp

; Character::attackingYou(class Character *, bool, bool);
?attackingYou@Character@@QEAAXPEAV1@_N1@Z proc
jmp function_pointers[303*8]
?attackingYou@Character@@QEAAXPEAV1@_N1@Z endp

; Character::iShotYou(class Character *, class Harpoon *, bool);
?iShotYou@Character@@QEAA_NPEAV1@PEAVHarpoon@@_N@Z proc
jmp function_pointers[304*8]
?iShotYou@Character@@QEAA_NPEAV1@PEAVHarpoon@@_N@Z endp

?_NV_hitByMeleeAttack@Character@@QEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAV1@PEAVCombatTechniqueData@@H@Z proc
?_NV_hitByMeleeAttack@Character@@QEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAV1@PEAVCombatTechniqueData@@H@Z endp

; Character::hitByMeleeAttack(enum CutDirection, class Damages &, class Character *, class CombatTechniqueData *, int);
?hitByMeleeAttack@Character@@UEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAV1@PEAVCombatTechniqueData@@H@Z proc
jmp function_pointers[305*8]
?hitByMeleeAttack@Character@@UEAA?AW4HitMaterialType@@W4CutDirection@@AEAVDamages@@PEAV1@PEAVCombatTechniqueData@@H@Z endp

?_NV_gettingEaten@Character@@QEAA_NMPEAV1@@Z proc
?_NV_gettingEaten@Character@@QEAA_NMPEAV1@@Z endp

; Character::gettingEaten(float, class Character *);
?gettingEaten@Character@@UEAA_NMPEAV1@@Z proc
jmp function_pointers[306*8]
?gettingEaten@Character@@UEAA_NMPEAV1@@Z endp

; Character::_startStumble(enum CutDirection, class Damages &, class GameData *, class Character *);
?_startStumble@Character@@QEAAXW4CutDirection@@AEAVDamages@@PEAVGameData@@PEAV1@@Z proc
jmp function_pointers[307*8]
?_startStumble@Character@@QEAAXW4CutDirection@@AEAVDamages@@PEAVGameData@@PEAV1@@Z endp

; Character::getAttackOriginationDirection(class Character *);
?getAttackOriginationDirection@Character@@QEAA?AW4CutOrigination@@PEAV1@@Z proc
jmp function_pointers[308*8]
?getAttackOriginationDirection@Character@@QEAA?AW4CutOrigination@@PEAV1@@Z endp

; Character::convertCutDirection(enum CutDirection, enum CutOrigination);
?convertCutDirection@Character@@QEAA?AW4CutDirection@@W42@W4CutOrigination@@@Z proc
jmp function_pointers[309*8]
?convertCutDirection@Character@@QEAA?AW4CutDirection@@W42@W4CutOrigination@@@Z endp

; Character::convertCutDirection(enum CutDirection, class Character *);
?convertCutDirection@Character@@QEAA?AW4CutDirection@@W42@PEAV1@@Z proc
jmp function_pointers[310*8]
?convertCutDirection@Character@@QEAA?AW4CutDirection@@W42@PEAV1@@Z endp

; Character::stumbleState();
?stumbleState@Character@@QEAA_NXZ proc
jmp function_pointers[311*8]
?stumbleState@Character@@QEAA_NXZ endp

?_NV_setAge@Character@@QEAAXM@Z proc
?_NV_setAge@Character@@QEAAXM@Z endp

; Character::setAge(float);
?setAge@Character@@UEAAXM@Z proc
jmp function_pointers[312*8]
?setAge@Character@@UEAAXM@Z endp

?_NV_setFaction@Character@@QEAAXPEAVFaction@@PEAVActivePlatoon@@@Z proc
?_NV_setFaction@Character@@QEAAXPEAVFaction@@PEAVActivePlatoon@@@Z endp

; Character::setFaction(class Faction *, class ActivePlatoon *);
?setFaction@Character@@UEAAXPEAVFaction@@PEAVActivePlatoon@@@Z proc
jmp function_pointers[313*8]
?setFaction@Character@@UEAAXPEAVFaction@@PEAVActivePlatoon@@@Z endp

?_NV_getAge@Character@@QEBAMXZ proc
?_NV_getAge@Character@@QEBAMXZ endp

; Character::getAge();
?getAge@Character@@UEBAMXZ proc
jmp function_pointers[314*8]
?getAge@Character@@UEBAMXZ endp

?_NV_getAge0to1@Character@@QEBAMXZ proc
?_NV_getAge0to1@Character@@QEBAMXZ endp

; Character::getAge0to1();
?getAge0to1@Character@@UEBAMXZ proc
jmp function_pointers[315*8]
?getAge0to1@Character@@UEBAMXZ endp

?_NV_getAgeString@Character@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
?_NV_getAgeString@Character@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; Character::getAgeString();
?getAgeString@Character@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[316*8]
?getAgeString@Character@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

?_NV_getAgeInverse@Character@@QEBAMXZ proc
?_NV_getAgeInverse@Character@@QEBAMXZ endp

; Character::getAgeInverse();
?getAgeInverse@Character@@UEBAMXZ proc
jmp function_pointers[317*8]
?getAgeInverse@Character@@UEBAMXZ endp

; Character::reThinkCurrentAIAction();
?reThinkCurrentAIAction@Character@@QEAAXXZ proc
jmp function_pointers[318*8]
?reThinkCurrentAIAction@Character@@QEAAXXZ endp

; Character::getBody();
?getBody@Character@@QEAAPEAVCharBody@@XZ proc
jmp function_pointers[319*8]
?getBody@Character@@QEAAPEAVCharBody@@XZ endp

; Character::getCombatClass();
?getCombatClass@Character@@QEBAPEAVCombatClass@@XZ proc
jmp function_pointers[320*8]
?getCombatClass@Character@@QEBAPEAVCombatClass@@XZ endp

; Character::getStats();
?getStats@Character@@QEAAPEAVCharStats@@XZ proc
jmp function_pointers[321*8]
?getStats@Character@@QEAAPEAVCharStats@@XZ endp

; Character::getMedical();
?getMedical@Character@@QEAAPEAVMedicalSystem@@XZ proc
jmp function_pointers[322*8]
?getMedical@Character@@QEAAPEAVMedicalSystem@@XZ endp

; Character::getOwnerships();
?getOwnerships@Character@@QEBAPEAVOwnerships@@XZ proc
jmp function_pointers[323*8]
?getOwnerships@Character@@QEBAPEAVOwnerships@@XZ endp

; Character::getAI();
?getAI@Character@@QEAAPEAVAI@@XZ proc
jmp function_pointers[324*8]
?getAI@Character@@QEAAPEAVAI@@XZ endp

; Character::getSquadMissionTarget(class hand &);
?getSquadMissionTarget@Character@@QEAAXAEAVhand@@@Z proc
jmp function_pointers[325*8]
?getSquadMissionTarget@Character@@QEAAXAEAVhand@@@Z endp

; Character::getAttackTarget();
?getAttackTarget@Character@@QEBA?AVhand@@XZ proc
jmp function_pointers[326*8]
?getAttackTarget@Character@@QEBA?AVhand@@XZ endp

; Character::isInCombatMode(bool, bool);
?isInCombatMode@Character@@QEBA_N_N0@Z proc
jmp function_pointers[327*8]
?isInCombatMode@Character@@QEBA_N_N0@Z endp

; Character::isInRangedCombatMode();
?isInRangedCombatMode@Character@@QEBA_NXZ proc
jmp function_pointers[328*8]
?isInRangedCombatMode@Character@@QEBA_NXZ endp

; Character::isLiterallyUnderMeleeAttackRightNowForSure();
?isLiterallyUnderMeleeAttackRightNowForSure@Character@@QEBA_NXZ proc
jmp function_pointers[329*8]
?isLiterallyUnderMeleeAttackRightNowForSure@Character@@QEBA_NXZ endp

; Character::_isLiterallyUnderMeleeAttackRightNowForSure_update();
?_isLiterallyUnderMeleeAttackRightNowForSure_update@Character@@QEAAXXZ proc
jmp function_pointers[330*8]
?_isLiterallyUnderMeleeAttackRightNowForSure_update@Character@@QEAAXXZ endp

; Character::conglomerateTagsFor(class Character *);
?conglomerateTagsFor@Character@@QEAAIPEAV1@@Z proc
jmp function_pointers[331*8]
?conglomerateTagsFor@Character@@QEAAIPEAV1@@Z endp

; Character::isPrisonerFreeToGo();
?isPrisonerFreeToGo@Character@@QEAA_NXZ proc
jmp function_pointers[332*8]
?isPrisonerFreeToGo@Character@@QEAA_NXZ endp

; Character::clearTempEnemyStatus(class Character *);
?clearTempEnemyStatus@Character@@QEAAXPEAV1@@Z proc
jmp function_pointers[333*8]
?clearTempEnemyStatus@Character@@QEAAXPEAV1@@Z endp

; Character::clearAllTempEnemyStatuses(enum CharacterPerceptionTags_ShortTerm);
?clearAllTempEnemyStatuses@Character@@QEAAXW4CharacterPerceptionTags_ShortTerm@@@Z proc
jmp function_pointers[334*8]
?clearAllTempEnemyStatuses@Character@@QEAAXW4CharacterPerceptionTags_ShortTerm@@@Z endp

; Character::rememberCharacter(class Character *, enum CharacterPerceptionTags_ShortTerm);
?rememberCharacter@Character@@QEAAXPEAV1@W4CharacterPerceptionTags_ShortTerm@@@Z proc
jmp function_pointers[335*8]
?rememberCharacter@Character@@QEAAXPEAV1@W4CharacterPerceptionTags_ShortTerm@@@Z endp

; Character::rememberCharacter(class Character *, enum CharacterPerceptionTags_LongTerm);
?rememberCharacter@Character@@QEAAXPEAV1@W4CharacterPerceptionTags_LongTerm@@@Z proc
jmp function_pointers[336*8]
?rememberCharacter@Character@@QEAAXPEAV1@W4CharacterPerceptionTags_LongTerm@@@Z endp

; Character::getCharacterMemoryTag(class Character *, enum CharacterPerceptionTags_LongTerm);
?getCharacterMemoryTag@Character@@QEAA_NPEAV1@W4CharacterPerceptionTags_LongTerm@@@Z proc
jmp function_pointers[337*8]
?getCharacterMemoryTag@Character@@QEAA_NPEAV1@W4CharacterPerceptionTags_LongTerm@@@Z endp

; Character::getCharacterMemoryTag(class Character *, enum CharacterPerceptionTags_ShortTerm);
?getCharacterMemoryTag@Character@@QEAA_NPEAV1@W4CharacterPerceptionTags_ShortTerm@@@Z proc
jmp function_pointers[338*8]
?getCharacterMemoryTag@Character@@QEAA_NPEAV1@W4CharacterPerceptionTags_ShortTerm@@@Z endp

; Character::lastSeenInHoursAgo(class Character *);
?lastSeenInHoursAgo@Character@@QEAAMPEAV1@@Z proc
jmp function_pointers[339*8]
?lastSeenInHoursAgo@Character@@QEAAMPEAV1@@Z endp

; Character::haveMetBefore(class Character *);
?haveMetBefore@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[340*8]
?haveMetBefore@Character@@QEAA_NPEAV1@@Z endp

; Character::getIDForMemoryTagging();
?getIDForMemoryTagging@Character@@QEAA?AVhand@@XZ proc
jmp function_pointers[341*8]
?getIDForMemoryTagging@Character@@QEAA?AVhand@@XZ endp

; Character::getMovement();
?getMovement@Character@@QEAAPEAVCharMovement@@XZ proc
jmp function_pointers[342*8]
?getMovement@Character@@QEAAPEAVCharMovement@@XZ endp

?_NV_lookatPosition@Character@@QEAAXAEBVVector3@Ogre@@_N@Z proc
?_NV_lookatPosition@Character@@QEAAXAEBVVector3@Ogre@@_N@Z endp

; Character::lookatPosition(const class Ogre::Vector3 &, bool);
?lookatPosition@Character@@UEAAXAEBVVector3@Ogre@@_N@Z proc
jmp function_pointers[343*8]
?lookatPosition@Character@@UEAAXAEBVVector3@Ogre@@_N@Z endp

; Character::areYouGonnaGetMe(class Character *);
?areYouGonnaGetMe@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[344*8]
?areYouGonnaGetMe@Character@@QEAA_NPEAV1@@Z endp

; Character::getAllAttackers(class lektor<hand> &);
?getAllAttackers@Character@@QEAAAEAV?$lektor@Vhand@@@@AEAV2@@Z proc
jmp function_pointers[345*8]
?getAllAttackers@Character@@QEAAAEAV?$lektor@Vhand@@@@AEAV2@@Z endp

; Character::getAllAttackersCount();
?getAllAttackersCount@Character@@QEAAHXZ proc
jmp function_pointers[346*8]
?getAllAttackersCount@Character@@QEAAHXZ endp

?_NV_getRace@Character@@QEBAPEAVRaceData@@XZ proc
?_NV_getRace@Character@@QEBAPEAVRaceData@@XZ endp

; Character::getRace();
?getRace@Character@@UEBAPEAVRaceData@@XZ proc
jmp function_pointers[347*8]
?getRace@Character@@UEBAPEAVRaceData@@XZ endp

?_NV_setRace@Character@@QEAAXPEAVGameData@@@Z proc
?_NV_setRace@Character@@QEAAXPEAVGameData@@@Z endp

; Character::setRace(class GameData *);
?setRace@Character@@UEAAXPEAVGameData@@@Z proc
jmp function_pointers[348*8]
?setRace@Character@@UEAAXPEAVGameData@@@Z endp

; Character::getRadius();
?getRadius@Character@@QEAAMXZ proc
jmp function_pointers[349*8]
?getRadius@Character@@QEAAMXZ endp

; Character::isPlayerCharacter();
?isPlayerCharacter@Character@@QEBA_NXZ proc
jmp function_pointers[350*8]
?isPlayerCharacter@Character@@QEBA_NXZ endp

; Character::checkPlayerOrderForProblems(enum TaskType, class RootObject *);
?checkPlayerOrderForProblems@Character@@QEAA_NW4TaskType@@PEAVRootObject@@@Z proc
jmp function_pointers[351*8]
?checkPlayerOrderForProblems@Character@@QEAA_NW4TaskType@@PEAVRootObject@@@Z endp

; Character::breakFollowOrderLoop(const class hand &);
?breakFollowOrderLoop@Character@@QEAA_NAEBVhand@@@Z proc
jmp function_pointers[352*8]
?breakFollowOrderLoop@Character@@QEAA_NAEBVhand@@@Z endp

; Character::getTotalCarryWeight();
?getTotalCarryWeight@Character@@QEAAMXZ proc
jmp function_pointers[353*8]
?getTotalCarryWeight@Character@@QEAAMXZ endp

?_NV_getRangedWeapon@Character@@QEAAPEAVCrossbow@@XZ proc
?_NV_getRangedWeapon@Character@@QEAAPEAVCrossbow@@XZ endp

; Character::getRangedWeapon();
?getRangedWeapon@Character@@UEAAPEAVCrossbow@@XZ proc
jmp function_pointers[354*8]
?getRangedWeapon@Character@@UEAAPEAVCrossbow@@XZ endp

; Character::getUpperBodyArmour();
?getUpperBodyArmour@Character@@QEAAPEAVItem@@XZ proc
jmp function_pointers[355*8]
?getUpperBodyArmour@Character@@QEAAPEAVItem@@XZ endp

; Character::getLowerBodyArmour();
?getLowerBodyArmour@Character@@QEAAPEAVItem@@XZ proc
jmp function_pointers[356*8]
?getLowerBodyArmour@Character@@QEAAPEAVItem@@XZ endp

; Character::isInjured(bool);
?isInjured@Character@@QEBA_N_N@Z proc
jmp function_pointers[357*8]
?isInjured@Character@@QEBA_N_N@Z endp

; Character::shouldUseRangedWeapons();
?shouldUseRangedWeapons@Character@@QEAA_NXZ proc
jmp function_pointers[358*8]
?shouldUseRangedWeapons@Character@@QEAA_NXZ endp

; Character::getBoneWorldPosition(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getBoneWorldPosition@Character@@QEAA?AVVector3@Ogre@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[359*8]
?getBoneWorldPosition@Character@@QEAA?AVVector3@Ogre@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; Character::getAppearance();
?getAppearance@Character@@QEAAPEAVAppearanceBase@@XZ proc
jmp function_pointers[360*8]
?getAppearance@Character@@QEAAPEAVAppearanceBase@@XZ endp

; Character::_setPlatoon(class ActivePlatoon *, int);
?_setPlatoon@Character@@QEAAXPEAVActivePlatoon@@H@Z proc
jmp function_pointers[361*8]
?_setPlatoon@Character@@QEAAXPEAVActivePlatoon@@H@Z endp

; Character::getPlatoon();
?getPlatoon@Character@@QEBAPEAVActivePlatoon@@XZ proc
jmp function_pointers[362*8]
?getPlatoon@Character@@QEBAPEAVActivePlatoon@@XZ endp

; Character::hasPlatoon();
?hasPlatoon@Character@@QEBA_NXZ proc
jmp function_pointers[363*8]
?hasPlatoon@Character@@QEBA_NXZ endp

; Character::isInAPersistentPlatoon();
?isInAPersistentPlatoon@Character@@QEBA_NXZ proc
jmp function_pointers[364*8]
?isInAPersistentPlatoon@Character@@QEBA_NXZ endp

; Character::getBlackboard();
?getBlackboard@Character@@QEAAPEAVBlackboard@@XZ proc
jmp function_pointers[365*8]
?getBlackboard@Character@@QEAAPEAVBlackboard@@XZ endp

; Character::getSquadLeader();
?getSquadLeader@Character@@QEAAPEAV1@XZ proc
jmp function_pointers[366*8]
?getSquadLeader@Character@@QEAAPEAV1@XZ endp

; Character::getOrdersReciever();
?getOrdersReciever@Character@@QEBAPEAVOrdersReceiver@@XZ proc
jmp function_pointers[367*8]
?getOrdersReciever@Character@@QEBAPEAVOrdersReceiver@@XZ endp

; Character::preventRagdollMode();
?preventRagdollMode@Character@@QEBA_NXZ proc
jmp function_pointers[368*8]
?preventRagdollMode@Character@@QEBA_NXZ endp

; Character::setPrisonMode(bool, class UseableStuff *);
?setPrisonMode@Character@@QEAAX_NPEAVUseableStuff@@@Z proc
jmp function_pointers[369*8]
?setPrisonMode@Character@@QEAAX_NPEAVUseableStuff@@@Z endp

; Character::setBedMode(bool, class UseableStuff *);
?setBedMode@Character@@QEAAX_NPEAVUseableStuff@@@Z proc
jmp function_pointers[370*8]
?setBedMode@Character@@QEAAX_NPEAVUseableStuff@@@Z endp

; Character::setSlaveAIJob(bool);
?setSlaveAIJob@Character@@QEAAX_N@Z proc
jmp function_pointers[371*8]
?setSlaveAIJob@Character@@QEAAX_N@Z endp

; Character::setChainedMode(bool, const class hand &);
?setChainedMode@Character@@QEAAX_NAEBVhand@@@Z proc
jmp function_pointers[372*8]
?setChainedMode@Character@@QEAAX_NAEBVhand@@@Z endp

; Character::isChainedMode();
?isChainedMode@Character@@QEBA_NXZ proc
jmp function_pointers[373*8]
?isChainedMode@Character@@QEBA_NXZ endp

; Character::getChainedModeShackles();
?getChainedModeShackles@Character@@QEAAPEAVLockedArmour@@XZ proc
jmp function_pointers[374*8]
?getChainedModeShackles@Character@@QEAAPEAVLockedArmour@@XZ endp

; Character::getMySlaveOwner();
?getMySlaveOwner@Character@@QEBA?AVhand@@XZ proc
jmp function_pointers[375*8]
?getMySlaveOwner@Character@@QEBA?AVhand@@XZ endp

; Character::isSlave();
?isSlave@Character@@QEAA?AW4SlaveStateEnum@@XZ proc
jmp function_pointers[376*8]
?isSlave@Character@@QEAA?AW4SlaveStateEnum@@XZ endp

; Character::changeSlaveOwner(const class hand &);
?changeSlaveOwner@Character@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[377*8]
?changeSlaveOwner@Character@@QEAAXAEBVhand@@@Z endp

; Character::isMySlave(class Character *);
?isMySlave@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[378*8]
?isMySlave@Character@@QEAA_NPEAV1@@Z endp

; Character::isMyFactionsSlave(class Character *);
?isMyFactionsSlave@Character@@QEAA_NPEAV1@@Z proc
jmp function_pointers[379*8]
?isMyFactionsSlave@Character@@QEAA_NPEAV1@@Z endp

?_NV_isHeadShaven@Character@@QEBA_NXZ proc
?_NV_isHeadShaven@Character@@QEBA_NXZ endp

; Character::isHeadShaven();
?isHeadShaven@Character@@UEBA_NXZ proc
jmp function_pointers[380*8]
?isHeadShaven@Character@@UEBA_NXZ endp

; Character::runSlaveAnim(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, float, float);
?runSlaveAnim@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@MM@Z proc
jmp function_pointers[381*8]
?runSlaveAnim@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@MM@Z endp

; Character::endSlaveAnim(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?endSlaveAnim@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[382*8]
?endSlaveAnim@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; Character::updatePortraitGUIState();
?updatePortraitGUIState@Character@@QEAAXXZ proc
jmp function_pointers[383*8]
?updatePortraitGUIState@Character@@QEAAXXZ endp

; Character::pickupObject(class Character *);
?pickupObject@Character@@QEAAXPEAV1@@Z proc
jmp function_pointers[384*8]
?pickupObject@Character@@QEAAXPEAV1@@Z endp

; Character::getPickedUp(class Character *);
?getPickedUp@Character@@QEAAXPEAV1@@Z proc
jmp function_pointers[385*8]
?getPickedUp@Character@@QEAAXPEAV1@@Z endp

; Character::slaveAttachToBoneMode(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?slaveAttachToBoneMode@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[386*8]
?slaveAttachToBoneMode@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; Character::isDead();
?isDead@Character@@QEBA_NXZ proc
jmp function_pointers[387*8]
?isDead@Character@@QEBA_NXZ endp

; Character::isBeingCarried();
?isBeingCarried@Character@@QEBA_NXZ proc
jmp function_pointers[388*8]
?isBeingCarried@Character@@QEBA_NXZ endp

; Character::getCarryingObject();
?getCarryingObject@Character@@QEBA?AVhand@@XZ proc
jmp function_pointers[389*8]
?getCarryingObject@Character@@QEBA?AVhand@@XZ endp

; Character::chooseCarryObjectLeftOrRight();
?chooseCarryObjectLeftOrRight@Character@@QEAAXXZ proc
jmp function_pointers[390*8]
?chooseCarryObjectLeftOrRight@Character@@QEAAXXZ endp

; Character::dropCarriedObject(bool, bool);
?dropCarriedObject@Character@@QEAAX_N0@Z proc
jmp function_pointers[391*8]
?dropCarriedObject@Character@@QEAAX_N0@Z endp

; Character::getDropped(bool, bool);
?getDropped@Character@@QEAAX_N0@Z proc
jmp function_pointers[392*8]
?getDropped@Character@@QEAAX_N0@Z endp

; Character::getDiplomacyMultiplier();
?getDiplomacyMultiplier@Character@@QEAAMXZ proc
jmp function_pointers[393*8]
?getDiplomacyMultiplier@Character@@QEAAMXZ endp

?_NV_isEnemy@Character@@QEAA_NPEAV1@_N@Z proc
?_NV_isEnemy@Character@@QEAA_NPEAV1@_N@Z endp

; Character::isEnemy(class Character *, bool);
?isEnemy@Character@@UEAA_NPEAV1@_N@Z proc
jmp function_pointers[394*8]
?isEnemy@Character@@UEAA_NPEAV1@_N@Z endp

?_NV_isAlly@Character@@QEAA_NPEAV1@_N@Z proc
?_NV_isAlly@Character@@QEAA_NPEAV1@_N@Z endp

; Character::isAlly(class Character *, bool);
?isAlly@Character@@UEAA_NPEAV1@_N@Z proc
jmp function_pointers[395*8]
?isAlly@Character@@UEAA_NPEAV1@_N@Z endp

?_NV_getDefaultTaskRepertoireEnum@Character@@QEBAIXZ proc
?_NV_getDefaultTaskRepertoireEnum@Character@@QEBAIXZ endp

; Character::getDefaultTaskRepertoireEnum();
?getDefaultTaskRepertoireEnum@Character@@UEBAIXZ proc
jmp function_pointers[396*8]
?getDefaultTaskRepertoireEnum@Character@@UEBAIXZ endp

; Character::getAnimationClass();
?getAnimationClass@Character@@QEAAPEAVAnimationClass@@XZ proc
jmp function_pointers[397*8]
?getAnimationClass@Character@@QEAAPEAVAnimationClass@@XZ endp

; Character::getPredictedPosition(float);
?getPredictedPosition@Character@@QEAA?AVVector3@Ogre@@M@Z proc
jmp function_pointers[398*8]
?getPredictedPosition@Character@@QEAA?AVVector3@Ogre@@M@Z endp

; Character::carryModeT(bool, bool, bool);
?carryModeT@Character@@QEAAX_N00@Z proc
jmp function_pointers[399*8]
?carryModeT@Character@@QEAAX_N00@Z endp

; Character::_carryMode(bool, bool, bool);
?_carryMode@Character@@QEAAX_N00@Z proc
jmp function_pointers[400*8]
?_carryMode@Character@@QEAAX_N00@Z endp

; Character::recalculateTotalEquipmentSkillBonus();
?recalculateTotalEquipmentSkillBonus@Character@@QEAAXXZ proc
jmp function_pointers[401*8]
?recalculateTotalEquipmentSkillBonus@Character@@QEAAXXZ endp

?_NV_setupAudio@Character@@QEAAXXZ proc
?_NV_setupAudio@Character@@QEAAXXZ endp

; Character::setupAudio();
?setupAudio@Character@@UEAAXXZ proc
jmp function_pointers[402*8]
?setupAudio@Character@@UEAAXXZ endp

; Character::getAudioObject();
?getAudioObject@Character@@QEBA_KXZ proc
jmp function_pointers[403*8]
?getAudioObject@Character@@QEBA_KXZ endp

; Character::audioEvent(const char *, enum SoundRange);
?audioEvent@Character@@QEAA_NPEBDW4SoundRange@@@Z proc
jmp function_pointers[404*8]
?audioEvent@Character@@QEAA_NPEBDW4SoundRange@@@Z endp

; Character::audioValue(const char *, float);
?audioValue@Character@@QEBAXPEBDM@Z proc
jmp function_pointers[405*8]
?audioValue@Character@@QEBAXPEBDM@Z endp

; Character::audioValue(const char *, const char *);
?audioValue@Character@@QEBAXPEBD0@Z proc
jmp function_pointers[406*8]
?audioValue@Character@@QEBAXPEBD0@Z endp

; Character::setGroundType(enum GroundType);
?setGroundType@Character@@QEAAXW4GroundType@@@Z proc
jmp function_pointers[407*8]
?setGroundType@Character@@QEAAXW4GroundType@@@Z endp

; Character::getGroundType();
?getGroundType@Character@@QEAA?AW4GroundType@@XZ proc
jmp function_pointers[408*8]
?getGroundType@Character@@QEAA?AW4GroundType@@XZ endp

; Character::calculateMainArmourType();
?calculateMainArmourType@Character@@QEAAXXZ proc
jmp function_pointers[409*8]
?calculateMainArmourType@Character@@QEAAXXZ endp

; Character::getMainArmourType();
?getMainArmourType@Character@@QEBA?AW4ArmourType@@XZ proc
jmp function_pointers[410*8]
?getMainArmourType@Character@@QEBA?AW4ArmourType@@XZ endp

?_NV_wearingUniformOf@Character@@QEAA_NPEAVFaction@@@Z proc
?_NV_wearingUniformOf@Character@@QEAA_NPEAVFaction@@@Z endp

; Character::wearingUniformOf(class Faction *);
?wearingUniformOf@Character@@UEAA_NPEAVFaction@@@Z proc
jmp function_pointers[411*8]
?wearingUniformOf@Character@@UEAA_NPEAVFaction@@@Z endp

; Character::getUniformColorScheme();
?getUniformColorScheme@Character@@QEAAPEAVGameData@@XZ proc
jmp function_pointers[412*8]
?getUniformColorScheme@Character@@QEAAPEAVGameData@@XZ endp

; Character::canTakePlayerOrdersAtThisTime();
?canTakePlayerOrdersAtThisTime@Character@@QEAA_NXZ proc
jmp function_pointers[413*8]
?canTakePlayerOrdersAtThisTime@Character@@QEAA_NXZ endp

; Character::startEffect(class GameData *);
?startEffect@Character@@QEAA_NPEAVGameData@@@Z proc
jmp function_pointers[414*8]
?startEffect@Character@@QEAA_NPEAVGameData@@@Z endp

; Character::stopEffect(class GameData *);
?stopEffect@Character@@QEAA_NPEAVGameData@@@Z proc
jmp function_pointers[415*8]
?stopEffect@Character@@QEAA_NPEAVGameData@@@Z endp

; Character::stopAllEffects();
?stopAllEffects@Character@@QEAAXXZ proc
jmp function_pointers[416*8]
?stopAllEffects@Character@@QEAAXXZ endp

?_NV_notifyEffect@Character@@QEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z proc
?_NV_notifyEffect@Character@@QEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z endp

; Character::notifyEffect(enum EffectType::Enum, enum WeatherAffecting, float);
?notifyEffect@Character@@UEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z proc
jmp function_pointers[417*8]
?notifyEffect@Character@@UEAAXW4Enum@EffectType@@W4WeatherAffecting@@M@Z endp

?_NV_equipItem@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
?_NV_equipItem@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

; Character::equipItem(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Item *);
?equipItem@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
jmp function_pointers[418*8]
?equipItem@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

?_NV_unequipItem@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
?_NV_unequipItem@Character@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

; Character::unequipItem(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Item *);
?unequipItem@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
jmp function_pointers[419*8]
?unequipItem@Character@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

?_NV_validateInventorySections@Character@@QEAAXXZ proc
?_NV_validateInventorySections@Character@@QEAAXXZ endp

; Character::validateInventorySections();
?validateInventorySections@Character@@UEAAXXZ proc
jmp function_pointers[420*8]
?validateInventorySections@Character@@UEAAXXZ endp

; Character::processCharacterLoadTimeMessages();
?processCharacterLoadTimeMessages@Character@@QEAAXXZ proc
jmp function_pointers[421*8]
?processCharacterLoadTimeMessages@Character@@QEAAXXZ endp

; Character::wantsPathfinderActive();
?wantsPathfinderActive@Character@@QEAA_NXZ proc
jmp function_pointers[422*8]
?wantsPathfinderActive@Character@@QEAA_NXZ endp

; Character::_ragdollMode(const struct Character::RagdollMsg &);
?_ragdollMode@Character@@QEAA_NAEBURagdollMsg@1@@Z proc
jmp function_pointers[423*8]
?_ragdollMode@Character@@QEAA_NAEBURagdollMsg@1@@Z endp

; Character::calculateDestinationState(class Building *, class RootObject *, const class Ogre::Vector3 &);
?calculateDestinationState@Character@@QEAAXPEAVBuilding@@PEAVRootObject@@AEBVVector3@Ogre@@@Z proc
jmp function_pointers[424*8]
?calculateDestinationState@Character@@QEAAXPEAVBuilding@@PEAVRootObject@@AEBVVector3@Ogre@@@Z endp

; Character::generateWeapon(class GameData *, class GameData *);
?generateWeapon@Character@@QEAAPEAVItem@@PEAVGameData@@0@Z proc
jmp function_pointers[425*8]
?generateWeapon@Character@@QEAAPEAVItem@@PEAVGameData@@0@Z endp

?_NV_createPhysical@Character@@QEAA_NXZ proc
?_NV_createPhysical@Character@@QEAA_NXZ endp

; Character::createPhysical();
?createPhysical@Character@@UEAA_NXZ proc
jmp function_pointers[426*8]
?createPhysical@Character@@UEAA_NXZ endp

?_NV_destroyPhysical@Character@@QEAAXXZ proc
?_NV_destroyPhysical@Character@@QEAAXXZ endp

; Character::destroyPhysical();
?destroyPhysical@Character@@UEAAXXZ proc
jmp function_pointers[427*8]
?destroyPhysical@Character@@UEAAXXZ endp

; Character::createComponents(class GameDataCopyStandalone *);
?createComponents@Character@@QEAA_NPEAVGameDataCopyStandalone@@@Z proc
jmp function_pointers[428*8]
?createComponents@Character@@QEAA_NPEAVGameDataCopyStandalone@@@Z endp

?_NV_loadUnloadCheck@Character@@QEAAXXZ proc
?_NV_loadUnloadCheck@Character@@QEAAXXZ endp

; Character::loadUnloadCheck();
?loadUnloadCheck@Character@@UEAAXXZ proc
jmp function_pointers[429*8]
?loadUnloadCheck@Character@@UEAAXXZ endp

; Character::updateStateBroadcast(float);
?updateStateBroadcast@Character@@QEAAXM@Z proc
jmp function_pointers[430*8]
?updateStateBroadcast@Character@@QEAAXM@Z endp

; Character::setEffectBT(class GameData *, bool);
?setEffectBT@Character@@QEAAXPEAVGameData@@_N@Z proc
jmp function_pointers[431*8]
?setEffectBT@Character@@QEAAXPEAVGameData@@_N@Z endp

?_NV_postRagdollCallback@Character@@QEAAX_NW4Enum@RagdollPart@@@Z proc
?_NV_postRagdollCallback@Character@@QEAAX_NW4Enum@RagdollPart@@@Z endp

; Character::postRagdollCallback(bool, enum RagdollPart::Enum);
?postRagdollCallback@Character@@UEAAX_NW4Enum@RagdollPart@@@Z proc
jmp function_pointers[432*8]
?postRagdollCallback@Character@@UEAAX_NW4Enum@RagdollPart@@@Z endp

?_NV_reCalculateNaturalWeapon@Character@@QEAAXXZ proc
?_NV_reCalculateNaturalWeapon@Character@@QEAAXXZ endp

; Character::reCalculateNaturalWeapon();
?reCalculateNaturalWeapon@Character@@UEAAXXZ proc
jmp function_pointers[433*8]
?reCalculateNaturalWeapon@Character@@UEAAXXZ endp

?_CONSTRUCTOR@CharacterHuman@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z proc
?_CONSTRUCTOR@CharacterHuman@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z endp

; CharacterHuman::CharacterHuman(class GameData *, class Faction *, class hand);
??0CharacterHuman@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z proc
jmp function_pointers[434*8]
??0CharacterHuman@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z endp

?_DESTRUCTOR@CharacterHuman@@QEAAXXZ proc
?_DESTRUCTOR@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::~CharacterHuman();
??1CharacterHuman@@UEAA@XZ proc
jmp function_pointers[435*8]
??1CharacterHuman@@UEAA@XZ endp

?_NV_isHuman@CharacterHuman@@QEAAPEAV1@XZ proc
?_NV_isHuman@CharacterHuman@@QEAAPEAV1@XZ endp

; CharacterHuman::isHuman();
?isHuman@CharacterHuman@@UEAAPEAV1@XZ proc
jmp function_pointers[436*8]
?isHuman@CharacterHuman@@UEAAPEAV1@XZ endp

?_NV_drawWeapon@CharacterHuman@@QEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_drawWeapon@CharacterHuman@@QEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; CharacterHuman::drawWeapon(class Item *, class std::basic_string<char,std::char_traits<char>,std::allocator<char> >);
?drawWeapon@CharacterHuman@@UEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[437*8]
?drawWeapon@CharacterHuman@@UEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_sheatheWeapon@CharacterHuman@@QEAAXXZ proc
?_NV_sheatheWeapon@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::sheatheWeapon();
?sheatheWeapon@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[438*8]
?sheatheWeapon@CharacterHuman@@UEAAXXZ endp

?_NV_getCurrentWeapon@CharacterHuman@@QEAAPEAVWeapon@@XZ proc
?_NV_getCurrentWeapon@CharacterHuman@@QEAAPEAVWeapon@@XZ endp

; CharacterHuman::getCurrentWeapon();
?getCurrentWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ proc
jmp function_pointers[439*8]
?getCurrentWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ endp

?_NV_getThePreferredWeapon@CharacterHuman@@QEAAPEAVWeapon@@XZ proc
?_NV_getThePreferredWeapon@CharacterHuman@@QEAAPEAVWeapon@@XZ endp

; CharacterHuman::getThePreferredWeapon();
?getThePreferredWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ proc
jmp function_pointers[440*8]
?getThePreferredWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ endp

?_NV_getRangedWeapon@CharacterHuman@@QEAAPEAVCrossbow@@XZ proc
?_NV_getRangedWeapon@CharacterHuman@@QEAAPEAVCrossbow@@XZ endp

; CharacterHuman::getRangedWeapon();
?getRangedWeapon@CharacterHuman@@UEAAPEAVCrossbow@@XZ proc
jmp function_pointers[441*8]
?getRangedWeapon@CharacterHuman@@UEAAPEAVCrossbow@@XZ endp

?_NV_serialise@CharacterHuman@@QEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z proc
?_NV_serialise@CharacterHuman@@QEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z endp

; CharacterHuman::serialise(class GameDataContainer *, class GameData *, class PosRotPair *);
?serialise@CharacterHuman@@UEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z proc
jmp function_pointers[442*8]
?serialise@CharacterHuman@@UEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z endp

?_NV_loadFromSerialise@CharacterHuman@@QEAAXPEAVGameSaveState@@@Z proc
?_NV_loadFromSerialise@CharacterHuman@@QEAAXPEAVGameSaveState@@@Z endp

; CharacterHuman::loadFromSerialise(class GameSaveState *);
?loadFromSerialise@CharacterHuman@@UEAAXPEAVGameSaveState@@@Z proc
jmp function_pointers[443*8]
?loadFromSerialise@CharacterHuman@@UEAAXPEAVGameSaveState@@@Z endp

?_NV_giveBirth@CharacterHuman@@QEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z proc
?_NV_giveBirth@CharacterHuman@@QEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z endp

; CharacterHuman::giveBirth(class GameDataCopyStandalone *, const class Ogre::Vector3 &, const class Ogre::Quaternion &, class GameSaveState *, class ActivePlatoon *, class Faction *);
?giveBirth@CharacterHuman@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z proc
jmp function_pointers[444*8]
?giveBirth@CharacterHuman@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z endp

?_NV_setupInventorySections@CharacterHuman@@QEAA_NPEAVGameSaveState@@@Z proc
?_NV_setupInventorySections@CharacterHuman@@QEAA_NPEAVGameSaveState@@@Z endp

; CharacterHuman::setupInventorySections(class GameSaveState *);
?setupInventorySections@CharacterHuman@@UEAA_NPEAVGameSaveState@@@Z proc
jmp function_pointers[445*8]
?setupInventorySections@CharacterHuman@@UEAA_NPEAVGameSaveState@@@Z endp

?_NV_validateInventorySections@CharacterHuman@@QEAAXXZ proc
?_NV_validateInventorySections@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::validateInventorySections();
?validateInventorySections@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[446*8]
?validateInventorySections@CharacterHuman@@UEAAXXZ endp

?_NV_setupAudio@CharacterHuman@@QEAAXXZ proc
?_NV_setupAudio@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::setupAudio();
?setupAudio@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[447*8]
?setupAudio@CharacterHuman@@UEAAXXZ endp

; CharacterHuman::shaveHead(bool);
?shaveHead@CharacterHuman@@QEAAX_N@Z proc
jmp function_pointers[448*8]
?shaveHead@CharacterHuman@@QEAAX_N@Z endp

?_NV_isHeadShaven@CharacterHuman@@QEBA_NXZ proc
?_NV_isHeadShaven@CharacterHuman@@QEBA_NXZ endp

; CharacterHuman::isHeadShaven();
?isHeadShaven@CharacterHuman@@UEBA_NXZ proc
jmp function_pointers[449*8]
?isHeadShaven@CharacterHuman@@UEBA_NXZ endp

?_NV_createAnimationClass@CharacterHuman@@QEAAXXZ proc
?_NV_createAnimationClass@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::createAnimationClass();
?createAnimationClass@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[450*8]
?createAnimationClass@CharacterHuman@@UEAAXXZ endp

?_NV_dropItem@CharacterHuman@@QEAAXPEAVRootObject@@@Z proc
?_NV_dropItem@CharacterHuman@@QEAAXPEAVRootObject@@@Z endp

; CharacterHuman::dropItem(class RootObject *);
?dropItem@CharacterHuman@@UEAAXPEAVRootObject@@@Z proc
jmp function_pointers[451*8]
?dropItem@CharacterHuman@@UEAAXPEAVRootObject@@@Z endp

; CharacterHuman::dropWeaponInHands();
?dropWeaponInHands@CharacterHuman@@QEAAXXZ proc
jmp function_pointers[452*8]
?dropWeaponInHands@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::dropWeaponInHandsFake();
?dropWeaponInHandsFake@CharacterHuman@@QEAAXXZ proc
jmp function_pointers[453*8]
?dropWeaponInHandsFake@CharacterHuman@@QEAAXXZ endp

?_NV_unequipItem@CharacterHuman@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
?_NV_unequipItem@CharacterHuman@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

; CharacterHuman::unequipItem(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Item *);
?unequipItem@CharacterHuman@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
jmp function_pointers[454*8]
?unequipItem@CharacterHuman@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

?_NV_weatherUpdate@CharacterHuman@@QEAAXM@Z proc
?_NV_weatherUpdate@CharacterHuman@@QEAAXM@Z endp

; CharacterHuman::weatherUpdate(float);
?weatherUpdate@CharacterHuman@@UEAAXM@Z proc
jmp function_pointers[455*8]
?weatherUpdate@CharacterHuman@@UEAAXM@Z endp

; CharacterHuman::leaveSheathEquipped(class std::basic_string<char,std::char_traits<char>,std::allocator<char> >, int);
?leaveSheathEquipped@CharacterHuman@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z proc
jmp function_pointers[456*8]
?leaveSheathEquipped@CharacterHuman@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z endp

?_NV_postRagdollCallback@CharacterHuman@@QEAAX_NW4Enum@RagdollPart@@@Z proc
?_NV_postRagdollCallback@CharacterHuman@@QEAAX_NW4Enum@RagdollPart@@@Z endp

; CharacterHuman::postRagdollCallback(bool, enum RagdollPart::Enum);
?postRagdollCallback@CharacterHuman@@UEAAX_NW4Enum@RagdollPart@@@Z proc
jmp function_pointers[457*8]
?postRagdollCallback@CharacterHuman@@UEAAX_NW4Enum@RagdollPart@@@Z endp

?_NV_reCalculateNaturalWeapon@CharacterHuman@@QEAAXXZ proc
?_NV_reCalculateNaturalWeapon@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::reCalculateNaturalWeapon();
?reCalculateNaturalWeapon@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[458*8]
?reCalculateNaturalWeapon@CharacterHuman@@UEAAXXZ endp

?_NV_isAnimal@CharacterAnimal@@QEAAPEAV1@XZ proc
?_NV_isAnimal@CharacterAnimal@@QEAAPEAV1@XZ endp

; CharacterAnimal::isAnimal();
?isAnimal@CharacterAnimal@@UEAAPEAV1@XZ proc
jmp function_pointers[459*8]
?isAnimal@CharacterAnimal@@UEAAPEAV1@XZ endp

?_NV_createAnimationClass@CharacterAnimal@@QEAAXXZ proc
?_NV_createAnimationClass@CharacterAnimal@@QEAAXXZ endp

; CharacterAnimal::createAnimationClass();
?createAnimationClass@CharacterAnimal@@UEAAXXZ proc
jmp function_pointers[460*8]
?createAnimationClass@CharacterAnimal@@UEAAXXZ endp

?_NV_drawWeapon@CharacterAnimal@@QEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
?_NV_drawWeapon@CharacterAnimal@@QEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; CharacterAnimal::drawWeapon(class Item *, class std::basic_string<char,std::char_traits<char>,std::allocator<char> >);
?drawWeapon@CharacterAnimal@@UEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[461*8]
?drawWeapon@CharacterAnimal@@UEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

?_NV_sheatheWeapon@CharacterAnimal@@QEAAXXZ proc
?_NV_sheatheWeapon@CharacterAnimal@@QEAAXXZ endp

; CharacterAnimal::sheatheWeapon();
?sheatheWeapon@CharacterAnimal@@UEAAXXZ proc
jmp function_pointers[462*8]
?sheatheWeapon@CharacterAnimal@@UEAAXXZ endp

?_NV_getCurrentWeapon@CharacterAnimal@@QEAAPEAVWeapon@@XZ proc
?_NV_getCurrentWeapon@CharacterAnimal@@QEAAPEAVWeapon@@XZ endp

; CharacterAnimal::getCurrentWeapon();
?getCurrentWeapon@CharacterAnimal@@UEAAPEAVWeapon@@XZ proc
jmp function_pointers[463*8]
?getCurrentWeapon@CharacterAnimal@@UEAAPEAVWeapon@@XZ endp

?_NV_getThePreferredWeapon@CharacterAnimal@@QEAAPEAVWeapon@@XZ proc
?_NV_getThePreferredWeapon@CharacterAnimal@@QEAAPEAVWeapon@@XZ endp

; CharacterAnimal::getThePreferredWeapon();
?getThePreferredWeapon@CharacterAnimal@@UEAAPEAVWeapon@@XZ proc
jmp function_pointers[464*8]
?getThePreferredWeapon@CharacterAnimal@@UEAAPEAVWeapon@@XZ endp

?_NV_createInventoryLayout@CharacterAnimal@@QEAAPEAVInventoryLayout@@XZ proc
?_NV_createInventoryLayout@CharacterAnimal@@QEAAPEAVInventoryLayout@@XZ endp

; CharacterAnimal::createInventoryLayout();
?createInventoryLayout@CharacterAnimal@@UEAAPEAVInventoryLayout@@XZ proc
jmp function_pointers[465*8]
?createInventoryLayout@CharacterAnimal@@UEAAPEAVInventoryLayout@@XZ endp

?_NV_giveBirth@CharacterAnimal@@QEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z proc
?_NV_giveBirth@CharacterAnimal@@QEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z endp

; CharacterAnimal::giveBirth(class GameDataCopyStandalone *, const class Ogre::Vector3 &, const class Ogre::Quaternion &, class GameSaveState *, class ActivePlatoon *, class Faction *);
?giveBirth@CharacterAnimal@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z proc
jmp function_pointers[466*8]
?giveBirth@CharacterAnimal@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z endp

?_NV_setupInventorySections@CharacterAnimal@@QEAA_NPEAVGameSaveState@@@Z proc
?_NV_setupInventorySections@CharacterAnimal@@QEAA_NPEAVGameSaveState@@@Z endp

; CharacterAnimal::setupInventorySections(class GameSaveState *);
?setupInventorySections@CharacterAnimal@@UEAA_NPEAVGameSaveState@@@Z proc
jmp function_pointers[467*8]
?setupInventorySections@CharacterAnimal@@UEAA_NPEAVGameSaveState@@@Z endp

?_NV_setupAudio@CharacterAnimal@@QEAAXXZ proc
?_NV_setupAudio@CharacterAnimal@@QEAAXXZ endp

; CharacterAnimal::setupAudio();
?setupAudio@CharacterAnimal@@UEAAXXZ proc
jmp function_pointers[468*8]
?setupAudio@CharacterAnimal@@UEAAXXZ endp

?_NV_periodicUpdate@CharacterAnimal@@QEAAXXZ proc
?_NV_periodicUpdate@CharacterAnimal@@QEAAXXZ endp

; CharacterAnimal::periodicUpdate();
?periodicUpdate@CharacterAnimal@@UEAAXXZ proc
jmp function_pointers[469*8]
?periodicUpdate@CharacterAnimal@@UEAAXXZ endp

?_NV_setAge@CharacterAnimal@@QEAAXM@Z proc
?_NV_setAge@CharacterAnimal@@QEAAXM@Z endp

; CharacterAnimal::setAge(float);
?setAge@CharacterAnimal@@UEAAXM@Z proc
jmp function_pointers[470*8]
?setAge@CharacterAnimal@@UEAAXM@Z endp

?_NV_getAge@CharacterAnimal@@QEBAMXZ proc
?_NV_getAge@CharacterAnimal@@QEBAMXZ endp

; CharacterAnimal::getAge();
?getAge@CharacterAnimal@@UEBAMXZ proc
jmp function_pointers[471*8]
?getAge@CharacterAnimal@@UEBAMXZ endp

?_NV_getAgeInverse@CharacterAnimal@@QEBAMXZ proc
?_NV_getAgeInverse@CharacterAnimal@@QEBAMXZ endp

; CharacterAnimal::getAgeInverse();
?getAgeInverse@CharacterAnimal@@UEBAMXZ proc
jmp function_pointers[472*8]
?getAgeInverse@CharacterAnimal@@UEBAMXZ endp

?_NV_getAge0to1@CharacterAnimal@@QEBAMXZ proc
?_NV_getAge0to1@CharacterAnimal@@QEBAMXZ endp

; CharacterAnimal::getAge0to1();
?getAge0to1@CharacterAnimal@@UEBAMXZ proc
jmp function_pointers[473*8]
?getAge0to1@CharacterAnimal@@UEBAMXZ endp

?_NV_getDefaultTaskRepertoireEnum@CharacterAnimal@@QEBAIXZ proc
?_NV_getDefaultTaskRepertoireEnum@CharacterAnimal@@QEBAIXZ endp

; CharacterAnimal::getDefaultTaskRepertoireEnum();
?getDefaultTaskRepertoireEnum@CharacterAnimal@@UEBAIXZ proc
jmp function_pointers[474*8]
?getDefaultTaskRepertoireEnum@CharacterAnimal@@UEBAIXZ endp

?_NV_canGoIndoors@CharacterAnimal@@QEBA_NPEAVBuilding@@@Z proc
?_NV_canGoIndoors@CharacterAnimal@@QEBA_NPEAVBuilding@@@Z endp

; CharacterAnimal::canGoIndoors(class Building *);
?canGoIndoors@CharacterAnimal@@UEBA_NPEAVBuilding@@@Z proc
jmp function_pointers[475*8]
?canGoIndoors@CharacterAnimal@@UEBA_NPEAVBuilding@@@Z endp

?_NV_getSmellHuntingThresholdBlood@CharacterAnimal@@QEBAMXZ proc
?_NV_getSmellHuntingThresholdBlood@CharacterAnimal@@QEBAMXZ endp

; CharacterAnimal::getSmellHuntingThresholdBlood();
?getSmellHuntingThresholdBlood@CharacterAnimal@@UEBAMXZ proc
jmp function_pointers[476*8]
?getSmellHuntingThresholdBlood@CharacterAnimal@@UEBAMXZ endp

?_NV_getSmellHuntingThresholdEggs@CharacterAnimal@@QEBAMXZ proc
?_NV_getSmellHuntingThresholdEggs@CharacterAnimal@@QEBAMXZ endp

; CharacterAnimal::getSmellHuntingThresholdEggs();
?getSmellHuntingThresholdEggs@CharacterAnimal@@UEBAMXZ proc
jmp function_pointers[477*8]
?getSmellHuntingThresholdEggs@CharacterAnimal@@UEBAMXZ endp

?_NV_getHPMultiplier@CharacterAnimal@@QEBAMXZ proc
?_NV_getHPMultiplier@CharacterAnimal@@QEBAMXZ endp

; CharacterAnimal::getHPMultiplier();
?getHPMultiplier@CharacterAnimal@@UEBAMXZ proc
jmp function_pointers[478*8]
?getHPMultiplier@CharacterAnimal@@UEBAMXZ endp

?_NV_foodUpdate@CharacterAnimal@@QEAAXXZ proc
?_NV_foodUpdate@CharacterAnimal@@QEAAXXZ endp

; CharacterAnimal::foodUpdate();
?foodUpdate@CharacterAnimal@@UEAAXXZ proc
jmp function_pointers[479*8]
?foodUpdate@CharacterAnimal@@UEAAXXZ endp

; CharacterAnimal::pickupItemInMouth(class Item *);
?pickupItemInMouth@CharacterAnimal@@QEAA_NPEAVItem@@@Z proc
jmp function_pointers[480*8]
?pickupItemInMouth@CharacterAnimal@@QEAA_NPEAVItem@@@Z endp

; CharacterAnimal::dropItemInMouth();
?dropItemInMouth@CharacterAnimal@@QEAA_NXZ proc
jmp function_pointers[481*8]
?dropItemInMouth@CharacterAnimal@@QEAA_NXZ endp

; CharacterAnimal::getItemInMouth();
?getItemInMouth@CharacterAnimal@@QEAAPEAVItem@@XZ proc
jmp function_pointers[482*8]
?getItemInMouth@CharacterAnimal@@QEAAPEAVItem@@XZ endp

; CharacterAnimal::eatItemInMouth();
?eatItemInMouth@CharacterAnimal@@QEAAXXZ proc
jmp function_pointers[483*8]
?eatItemInMouth@CharacterAnimal@@QEAAXXZ endp

?_CONSTRUCTOR@CharacterAnimal@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@M@Z proc
?_CONSTRUCTOR@CharacterAnimal@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@M@Z endp

; CharacterAnimal::CharacterAnimal(class GameData *, class Faction *, class hand, float);
??0CharacterAnimal@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@M@Z proc
jmp function_pointers[484*8]
??0CharacterAnimal@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@M@Z endp

?_DESTRUCTOR@CharacterAnimal@@QEAAXXZ proc
?_DESTRUCTOR@CharacterAnimal@@QEAAXXZ endp

; CharacterAnimal::~CharacterAnimal();
??1CharacterAnimal@@UEAA@XZ proc
jmp function_pointers[485*8]
??1CharacterAnimal@@UEAA@XZ endp

?_NV_init@CharacterAnimal@@QEAAXXZ proc
?_NV_init@CharacterAnimal@@QEAAXXZ endp

; CharacterAnimal::init();
?init@CharacterAnimal@@UEAAXXZ proc
jmp function_pointers[486*8]
?init@CharacterAnimal@@UEAAXXZ endp

?_NV_dropItem@CharacterAnimal@@QEAAXPEAVRootObject@@@Z proc
?_NV_dropItem@CharacterAnimal@@QEAAXPEAVRootObject@@@Z endp

; CharacterAnimal::dropItem(class RootObject *);
?dropItem@CharacterAnimal@@UEAAXPEAVRootObject@@@Z proc
jmp function_pointers[487*8]
?dropItem@CharacterAnimal@@UEAAXPEAVRootObject@@@Z endp

?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXAEBV01@@Z proc
?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXAEBV01@@Z endp

; GameWorld::SysMessage::SysMessage(const class GameWorld::SysMessage &);
??0SysMessage@GameWorld@@QEAA@AEBV01@@Z proc
jmp function_pointers[488*8]
??0SysMessage@GameWorld@@QEAA@AEBV01@@Z endp

?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXW4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z proc
?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXW4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z endp

; GameWorld::SysMessage::SysMessage(enum GameWorld::SysMessageEnum, const class hand &, const class hand &, bool, float, void *);
??0SysMessage@GameWorld@@QEAA@W4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z proc
jmp function_pointers[489*8]
??0SysMessage@GameWorld@@QEAA@W4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z endp

; GameWorld::SysMessage::operator==(const class GameWorld::SysMessage &);
??8SysMessage@GameWorld@@QEBA_NAEBV01@@Z proc
jmp function_pointers[490*8]
??8SysMessage@GameWorld@@QEBA_NAEBV01@@Z endp

; GameWorld::justLoadFactionRelations(class GameDataManager *);
?justLoadFactionRelations@GameWorld@@QEAAXPEAVGameDataManager@@@Z proc
jmp function_pointers[491*8]
?justLoadFactionRelations@GameWorld@@QEAAXPEAVGameDataManager@@@Z endp

; GameWorld::startUpThreads();
?startUpThreads@GameWorld@@QEAA_NXZ proc
jmp function_pointers[492*8]
?startUpThreads@GameWorld@@QEAA_NXZ endp

?_CONSTRUCTOR@GameWorld@@QEAAXXZ proc
?_CONSTRUCTOR@GameWorld@@QEAAXXZ endp

; GameWorld::GameWorld();
??0GameWorld@@QEAA@XZ proc
jmp function_pointers[493*8]
??0GameWorld@@QEAA@XZ endp

?_DESTRUCTOR@GameWorld@@QEAAXXZ proc
?_DESTRUCTOR@GameWorld@@QEAAXXZ endp

; GameWorld::~GameWorld();
??1GameWorld@@QEAA@XZ proc
jmp function_pointers[494*8]
??1GameWorld@@QEAA@XZ endp

; GameWorld::start(class RendererT *);
?start@GameWorld@@QEAA_NPEAVRendererT@@@Z proc
jmp function_pointers[495*8]
?start@GameWorld@@QEAA_NPEAVRendererT@@@Z endp

; GameWorld::resetGame();
?resetGame@GameWorld@@QEAAXXZ proc
jmp function_pointers[496*8]
?resetGame@GameWorld@@QEAAXXZ endp

; GameWorld::_clearAndDestroyGameWorldStuff();
?_clearAndDestroyGameWorldStuff@GameWorld@@QEAAXXZ proc
jmp function_pointers[497*8]
?_clearAndDestroyGameWorldStuff@GameWorld@@QEAAXXZ endp

; GameWorld::initialisation();
?initialisation@GameWorld@@QEAA_NXZ proc
jmp function_pointers[498*8]
?initialisation@GameWorld@@QEAA_NXZ endp

; GameWorld::initialisationGameData();
?initialisationGameData@GameWorld@@QEAA_NXZ proc
jmp function_pointers[499*8]
?initialisationGameData@GameWorld@@QEAA_NXZ endp

; GameWorld::dailyUpdates();
?dailyUpdates@GameWorld@@QEAAXXZ proc
jmp function_pointers[500*8]
?dailyUpdates@GameWorld@@QEAAXXZ endp

; GameWorld::initialiseNewGameWorld(class GameDataManager *);
?initialiseNewGameWorld@GameWorld@@QEAAXPEAVGameDataManager@@@Z proc
jmp function_pointers[501*8]
?initialiseNewGameWorld@GameWorld@@QEAAXPEAVGameDataManager@@@Z endp

; GameWorld::errorToLogReleaseMode(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?errorToLogReleaseMode@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[502*8]
?errorToLogReleaseMode@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::errorD(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?errorD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[503*8]
?errorD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::logToSave(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?logToSave@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[504*8]
?logToSave@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::log(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?log@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[505*8]
?log@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::logDebug(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[506*8]
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; GameWorld::logDebug(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[507*8]
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::destroy(class Ogre::MovableObject *);
?destroy@GameWorld@@QEAAXPEAVMovableObject@Ogre@@@Z proc
jmp function_pointers[508*8]
?destroy@GameWorld@@QEAAXPEAVMovableObject@Ogre@@@Z endp

; GameWorld::destroy(class AttachedEntity *);
?destroy@GameWorld@@QEAAXPEAVAttachedEntity@@@Z proc
jmp function_pointers[509*8]
?destroy@GameWorld@@QEAAXPEAVAttachedEntity@@@Z endp

; GameWorld::destroy(class TownBuildingsManager *);
?destroy@GameWorld@@QEAAXPEAVTownBuildingsManager@@@Z proc
jmp function_pointers[510*8]
?destroy@GameWorld@@QEAAXPEAVTownBuildingsManager@@@Z endp

; GameWorld::destroy(class NestBatcher *);
?destroy@GameWorld@@QEAAXPEAVNestBatcher@@@Z proc
jmp function_pointers[511*8]
?destroy@GameWorld@@QEAAXPEAVNestBatcher@@@Z endp

; GameWorld::destroy(class RootObject *, bool, const char *);
?destroy@GameWorld@@QEAA_NPEAVRootObject@@_NPEBD@Z proc
jmp function_pointers[512*8]
?destroy@GameWorld@@QEAA_NPEAVRootObject@@_NPEBD@Z endp

; GameWorld::destroy(class GameData *);
?destroy@GameWorld@@QEAAXPEAVGameData@@@Z proc
jmp function_pointers[513*8]
?destroy@GameWorld@@QEAAXPEAVGameData@@@Z endp

; GameWorld::getIsInKillList(class RootObject *);
?getIsInKillList@GameWorld@@QEAA_NPEAVRootObject@@@Z proc
jmp function_pointers[514*8]
?getIsInKillList@GameWorld@@QEAA_NPEAVRootObject@@@Z endp

; GameWorld::flushKillList();
?flushKillList@GameWorld@@QEAAXXZ proc
jmp function_pointers[515*8]
?flushKillList@GameWorld@@QEAAXXZ endp

; GameWorld::dynamicDestroyBuilding(const class hand &);
?dynamicDestroyBuilding@GameWorld@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[516*8]
?dynamicDestroyBuilding@GameWorld@@QEAAXAEBVhand@@@Z endp

; GameWorld::allThreadQueuesAreClear();
?allThreadQueuesAreClear@GameWorld@@QEAA_NXZ proc
jmp function_pointers[517*8]
?allThreadQueuesAreClear@GameWorld@@QEAA_NXZ endp

; GameWorld::initBaseMods();
?initBaseMods@GameWorld@@QEAAXXZ proc
jmp function_pointers[518*8]
?initBaseMods@GameWorld@@QEAAXXZ endp

; GameWorld::initModsList();
?initModsList@GameWorld@@QEAAXXZ proc
jmp function_pointers[519*8]
?initModsList@GameWorld@@QEAAXXZ endp

; GameWorld::getModsListFromConfig();
?getModsListFromConfig@GameWorld@@QEAA?AV?$lektor@PEAVModInfo@@@@XZ proc
jmp function_pointers[520*8]
?getModsListFromConfig@GameWorld@@QEAA?AV?$lektor@PEAVModInfo@@@@XZ endp

; GameWorld::getAllModsList();
?getAllModsList@GameWorld@@QEBAAEBV?$lektor@PEAVModInfo@@@@XZ proc
jmp function_pointers[521*8]
?getAllModsList@GameWorld@@QEBAAEBV?$lektor@PEAVModInfo@@@@XZ endp

; GameWorld::getModIndex(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getModIndex@GameWorld@@QEBAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[522*8]
?getModIndex@GameWorld@@QEBAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::getModLeveldataFolder(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getModLeveldataFolder@GameWorld@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z proc
jmp function_pointers[523*8]
?getModLeveldataFolder@GameWorld@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z endp

; GameWorld::getObjectsWithinSphere(class lektor<RootObject *> &, const class Ogre::Vector3 &, float, enum itemType, int, class RootObject *);
?getObjectsWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MW4itemType@@HPEAVRootObject@@@Z proc
jmp function_pointers[524*8]
?getObjectsWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MW4itemType@@HPEAVRootObject@@@Z endp

; GameWorld::getCharactersWithinSphere(class lektor<RootObject *> &, const class Ogre::Vector3 &, float, float, float, int, int, class RootObject *);
?getCharactersWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MMMHHPEAVRootObject@@@Z proc
jmp function_pointers[525*8]
?getCharactersWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MMMHHPEAVRootObject@@@Z endp

; GameWorld::getObjectsWithinBox(class lektor<RootObject *> &, const class Ogre::Vector3 &, const class Ogre::Vector3 &, const class Ogre::Quaternion &, enum itemType, int, class RootObject *);
?getObjectsWithinBox@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@1AEBVQuaternion@4@W4itemType@@HPEAVRootObject@@@Z proc
jmp function_pointers[526*8]
?getObjectsWithinBox@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@1AEBVQuaternion@4@W4itemType@@HPEAVRootObject@@@Z endp

; GameWorld::buildingIntersectionTestCapsule(const class Ogre::Vector3 &, float, float, class RootObject *);
?buildingIntersectionTestCapsule@GameWorld@@QEAA_NAEBVVector3@Ogre@@MMPEAVRootObject@@@Z proc
jmp function_pointers[527*8]
?buildingIntersectionTestCapsule@GameWorld@@QEAA_NAEBVVector3@Ogre@@MMPEAVRootObject@@@Z endp

; GameWorld::getLightLevel(const class Ogre::Vector3 &, int, bool);
?getLightLevel@GameWorld@@QEBAMAEBVVector3@Ogre@@H_N@Z proc
jmp function_pointers[528*8]
?getLightLevel@GameWorld@@QEBAMAEBVVector3@Ogre@@H_N@Z endp

; GameWorld::populateMapArea_nonPermanent(class ZoneMap *, int, bool);
?populateMapArea_nonPermanent@GameWorld@@QEAAXPEAVZoneMap@@H_N@Z proc
jmp function_pointers[529*8]
?populateMapArea_nonPermanent@GameWorld@@QEAAXPEAVZoneMap@@H_N@Z endp

; GameWorld::findValidSpawnPos(class Ogre::Vector3 &, const class Ogre::Vector3 &);
?findValidSpawnPos@GameWorld@@QEAA_NAEAVVector3@Ogre@@AEBV23@@Z proc
jmp function_pointers[530*8]
?findValidSpawnPos@GameWorld@@QEAA_NAEAVVector3@Ogre@@AEBV23@@Z endp

; GameWorld::togglePause(bool);
?togglePause@GameWorld@@QEAAX_N@Z proc
jmp function_pointers[531*8]
?togglePause@GameWorld@@QEAAX_N@Z endp

; GameWorld::getFrameSpeedMultiplier();
?getFrameSpeedMultiplier@GameWorld@@QEBAMXZ proc
jmp function_pointers[532*8]
?getFrameSpeedMultiplier@GameWorld@@QEBAMXZ endp

; GameWorld::setFrameSpeedMultiplier(float);
?setFrameSpeedMultiplier@GameWorld@@QEAAXM@Z proc
jmp function_pointers[533*8]
?setFrameSpeedMultiplier@GameWorld@@QEAAXM@Z endp

; GameWorld::setGameSpeed(float, bool);
?setGameSpeed@GameWorld@@QEAAXM_N@Z proc
jmp function_pointers[534*8]
?setGameSpeed@GameWorld@@QEAAXM_N@Z endp

; GameWorld::userPause(bool);
?userPause@GameWorld@@QEAAX_N@Z proc
jmp function_pointers[535*8]
?userPause@GameWorld@@QEAAX_N@Z endp

; GameWorld::isPaused();
?isPaused@GameWorld@@QEBA_NXZ proc
jmp function_pointers[536*8]
?isPaused@GameWorld@@QEBA_NXZ endp

; GameWorld::getCameraCenter();
?getCameraCenter@GameWorld@@QEBA?BVVector3@Ogre@@XZ proc
jmp function_pointers[537*8]
?getCameraCenter@GameWorld@@QEBA?BVVector3@Ogre@@XZ endp

; GameWorld::getCameraPos();
?getCameraPos@GameWorld@@QEBA?BVVector3@Ogre@@XZ proc
jmp function_pointers[538*8]
?getCameraPos@GameWorld@@QEBA?BVVector3@Ogre@@XZ endp

; GameWorld::fixNaNPosition(class Ogre::Vector3 &);
?fixNaNPosition@GameWorld@@QEBA_NAEAVVector3@Ogre@@@Z proc
jmp function_pointers[539*8]
?fixNaNPosition@GameWorld@@QEBA_NAEAVVector3@Ogre@@@Z endp

; GameWorld::getWindSpeed(const class Ogre::Vector3 &);
?getWindSpeed@GameWorld@@QEBAMAEBVVector3@Ogre@@@Z proc
jmp function_pointers[540*8]
?getWindSpeed@GameWorld@@QEBAMAEBVVector3@Ogre@@@Z endp

; GameWorld::isLoadingFromASaveGame();
?isLoadingFromASaveGame@GameWorld@@QEAA_NXZ proc
jmp function_pointers[541*8]
?isLoadingFromASaveGame@GameWorld@@QEAA_NXZ endp

; GameWorld::addToUpdateListMain(class Character *);
?addToUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z proc
jmp function_pointers[542*8]
?addToUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z endp

; GameWorld::removeFromUpdateListMain(class Character *);
?removeFromUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z proc
jmp function_pointers[543*8]
?removeFromUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z endp

; GameWorld::getCharacterUpdateList();
?getCharacterUpdateList@GameWorld@@QEBAAEBV?$unordered_set@PEAVCharacter@@U?$hash@PEAVCharacter@@@boost@@U?$equal_to@PEAVCharacter@@@std@@V?$STLAllocator@PEAVCharacter@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@XZ proc
jmp function_pointers[544*8]
?getCharacterUpdateList@GameWorld@@QEBAAEBV?$unordered_set@PEAVCharacter@@U?$hash@PEAVCharacter@@@boost@@U?$equal_to@PEAVCharacter@@@std@@V?$STLAllocator@PEAVCharacter@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@XZ endp

; GameWorld::addToDeathParade(class Character *);
?addToDeathParade@GameWorld@@QEAAXPEAVCharacter@@@Z proc
jmp function_pointers[545*8]
?addToDeathParade@GameWorld@@QEAAXPEAVCharacter@@@Z endp

; GameWorld::removeFromDeathParade(class Character *);
?removeFromDeathParade@GameWorld@@QEAA_NPEAVCharacter@@@Z proc
jmp function_pointers[546*8]
?removeFromDeathParade@GameWorld@@QEAA_NPEAVCharacter@@@Z endp

; GameWorld::removeFromDeathParadeByPlatoon(class Platoon *);
?removeFromDeathParadeByPlatoon@GameWorld@@QEAAXPEAVPlatoon@@@Z proc
jmp function_pointers[547*8]
?removeFromDeathParadeByPlatoon@GameWorld@@QEAAXPEAVPlatoon@@@Z endp

; GameWorld::getFromDeathParade(const class hand &);
?getFromDeathParade@GameWorld@@QEAAPEAVCharacter@@AEBVhand@@@Z proc
jmp function_pointers[548*8]
?getFromDeathParade@GameWorld@@QEAAPEAVCharacter@@AEBVhand@@@Z endp

; GameWorld::hideContextMenu();
?hideContextMenu@GameWorld@@QEAAXXZ proc
jmp function_pointers[549*8]
?hideContextMenu@GameWorld@@QEAAXXZ endp

; GameWorld::showPlayerAMessage_withLog(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?showPlayerAMessage_withLog@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[550*8]
?showPlayerAMessage_withLog@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; GameWorld::showPlayerAMessage(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?showPlayerAMessage@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[551*8]
?showPlayerAMessage@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; GameWorld::showPlayerAMessageD(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?showPlayerAMessageD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[552*8]
?showPlayerAMessageD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; GameWorld::playNotification(const char *);
?playNotification@GameWorld@@QEBAXPEBD@Z proc
jmp function_pointers[553*8]
?playNotification@GameWorld@@QEBAXPEBD@Z endp

; GameWorld::sysMessage(const class GameWorld::SysMessage &);
?sysMessage@GameWorld@@QEAAXAEBVSysMessage@1@@Z proc
jmp function_pointers[554*8]
?sysMessage@GameWorld@@QEAAXAEBVSysMessage@1@@Z endp

; GameWorld::sysMessageUrgent(const class GameWorld::SysMessage &);
?sysMessageUrgent@GameWorld@@QEAAXAEBVSysMessage@1@@Z proc
jmp function_pointers[555*8]
?sysMessageUrgent@GameWorld@@QEAAXAEBVSysMessage@1@@Z endp

; GameWorld::sysMessage_noDuplicates(const class GameWorld::SysMessage &);
?sysMessage_noDuplicates@GameWorld@@QEAAXAEBVSysMessage@1@@Z proc
jmp function_pointers[556*8]
?sysMessage_noDuplicates@GameWorld@@QEAAXAEBVSysMessage@1@@Z endp

?_NV_mainLoop_GPUSensitiveStuff@GameWorld@@QEAAXM@Z proc
?_NV_mainLoop_GPUSensitiveStuff@GameWorld@@QEAAXM@Z endp

; GameWorld::mainLoop_GPUSensitiveStuff(float);
?mainLoop_GPUSensitiveStuff@GameWorld@@UEAAXM@Z proc
jmp function_pointers[557*8]
?mainLoop_GPUSensitiveStuff@GameWorld@@UEAAXM@Z endp

; GameWorld::clearPortaitsUpdate();
?clearPortaitsUpdate@GameWorld@@QEAAXXZ proc
jmp function_pointers[558*8]
?clearPortaitsUpdate@GameWorld@@QEAAXXZ endp

; GameWorld::addPortraitUpdate(const class hand &);
?addPortraitUpdate@GameWorld@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[559*8]
?addPortraitUpdate@GameWorld@@QEAAXAEBVhand@@@Z endp

; GameWorld::removePortaitUpdate(const class hand &);
?removePortaitUpdate@GameWorld@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[560*8]
?removePortaitUpdate@GameWorld@@QEAAXAEBVhand@@@Z endp

; GameWorld::processSysMessages();
?processSysMessages@GameWorld@@QEAAXXZ proc
jmp function_pointers[561*8]
?processSysMessages@GameWorld@@QEAAXXZ endp

; GameWorld::getCollisionGroupType(enum itemType, enum NxShapesType &, unsigned int &);
?getCollisionGroupType@GameWorld@@QEAAXW4itemType@@AEAW4NxShapesType@@AEAI@Z proc
jmp function_pointers[562*8]
?getCollisionGroupType@GameWorld@@QEAAXW4itemType@@AEAW4NxShapesType@@AEAI@Z endp

; GameWorld::destroyDeathParade();
?destroyDeathParade@GameWorld@@QEAAXXZ proc
jmp function_pointers[563*8]
?destroyDeathParade@GameWorld@@QEAAXXZ endp

; GameWorld::processKeys();
?processKeys@GameWorld@@QEAAXXZ proc
jmp function_pointers[564*8]
?processKeys@GameWorld@@QEAAXXZ endp

; GameWorld::processThreadMessages();
?processThreadMessages@GameWorld@@QEAAXXZ proc
jmp function_pointers[565*8]
?processThreadMessages@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdate();
?charsUpdate@GameWorld@@QEAAXXZ proc
jmp function_pointers[566*8]
?charsUpdate@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdateUT();
?charsUpdateUT@GameWorld@@QEAAXXZ proc
jmp function_pointers[567*8]
?charsUpdateUT@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdatePaused();
?charsUpdatePaused@GameWorld@@QEAAXXZ proc
jmp function_pointers[568*8]
?charsUpdatePaused@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdateDeathParade();
?charsUpdateDeathParade@GameWorld@@QEAAXXZ proc
jmp function_pointers[569*8]
?charsUpdateDeathParade@GameWorld@@QEAAXXZ endp

; GameWorld::threadSafeRagdollUpdates();
?threadSafeRagdollUpdates@GameWorld@@QEAAXXZ proc
jmp function_pointers[570*8]
?threadSafeRagdollUpdates@GameWorld@@QEAAXXZ endp

; GameWorld::AINonRenderThread();
?AINonRenderThread@GameWorld@@QEAAPEAVThreadWannabe@@XZ proc
jmp function_pointers[571*8]
?AINonRenderThread@GameWorld@@QEAAPEAVThreadWannabe@@XZ endp

; GameWorld::processAttachmentsKillList();
?processAttachmentsKillList@GameWorld@@QEAAXXZ proc
jmp function_pointers[572*8]
?processAttachmentsKillList@GameWorld@@QEAAXXZ endp

; GameWorld::processKillList(bool);
?processKillList@GameWorld@@QEAAX_N@Z proc
jmp function_pointers[573*8]
?processKillList@GameWorld@@QEAAX_N@Z endp

; GameWorld::processUpdateRemovalList();
?processUpdateRemovalList@GameWorld@@QEAAXXZ proc
jmp function_pointers[574*8]
?processUpdateRemovalList@GameWorld@@QEAAXXZ endp

; GameWorld::loadAllPlatoons();
?loadAllPlatoons@GameWorld@@QEAAXXZ proc
jmp function_pointers[575*8]
?loadAllPlatoons@GameWorld@@QEAAXXZ endp

; GameWorld::reCalculateFortificationInsideOutsideStateForAllCharacters();
?reCalculateFortificationInsideOutsideStateForAllCharacters@GameWorld@@QEAAXXZ proc
jmp function_pointers[576*8]
?reCalculateFortificationInsideOutsideStateForAllCharacters@GameWorld@@QEAAXXZ endp

; GameWorld::getTimeStamp();
?getTimeStamp@GameWorld@@QEAANXZ proc
jmp function_pointers[577*8]
?getTimeStamp@GameWorld@@QEAANXZ endp

; GameWorld::getTimeFromStamp(const class TimeOfDay &);
?getTimeFromStamp@GameWorld@@QEAA?AVTimeOfDay@@AEBV2@@Z proc
jmp function_pointers[578*8]
?getTimeFromStamp@GameWorld@@QEAA?AVTimeOfDay@@AEBV2@@Z endp

; GameWorld::getTimeFromStamp(double);
?getTimeFromStamp@GameWorld@@QEAAMN@Z proc
jmp function_pointers[579*8]
?getTimeFromStamp@GameWorld@@QEAAMN@Z endp

; GameWorld::getTimeFromStamp_inGameHours(double);
?getTimeFromStamp_inGameHours@GameWorld@@QEAAMN@Z proc
jmp function_pointers[580*8]
?getTimeFromStamp_inGameHours@GameWorld@@QEAAMN@Z endp

; GameWorld::getTimeStamp_inGameHours();
?getTimeStamp_inGameHours@GameWorld@@QEAA?AVTimeOfDay@@XZ proc
jmp function_pointers[581*8]
?getTimeStamp_inGameHours@GameWorld@@QEAA?AVTimeOfDay@@XZ endp

; GameWorld::getLengthOfHourInRealSeconds();
?getLengthOfHourInRealSeconds@GameWorld@@QEAAMXZ proc
jmp function_pointers[582*8]
?getLengthOfHourInRealSeconds@GameWorld@@QEAAMXZ endp

; SaveManager::getSingleton();
?getSingleton@SaveManager@@SAPEAV1@XZ proc
jmp function_pointers[583*8]
?getSingleton@SaveManager@@SAPEAV1@XZ endp

; SaveManager::isVisible();
?isVisible@SaveManager@@QEAAHXZ proc
jmp function_pointers[584*8]
?isVisible@SaveManager@@QEAAHXZ endp

; SaveManager::showSave();
?showSave@SaveManager@@QEAAXXZ proc
jmp function_pointers[585*8]
?showSave@SaveManager@@QEAAXXZ endp

; SaveManager::showLoad();
?showLoad@SaveManager@@QEAAXXZ proc
jmp function_pointers[586*8]
?showLoad@SaveManager@@QEAAXXZ endp

; SaveManager::showImport();
?showImport@SaveManager@@QEAAXXZ proc
jmp function_pointers[587*8]
?showImport@SaveManager@@QEAAXXZ endp

; SaveManager::hide();
?hide@SaveManager@@QEAAXXZ proc
jmp function_pointers[588*8]
?hide@SaveManager@@QEAAXXZ endp

; SaveManager::newGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?newGame@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[589*8]
?newGame@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; SaveManager::save(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?save@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[590*8]
?save@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; SaveManager::load(const struct SaveInfo &, bool);
?load@SaveManager@@QEAAXAEBUSaveInfo@@_N@Z proc
jmp function_pointers[591*8]
?load@SaveManager@@QEAAXAEBUSaveInfo@@_N@Z endp

; SaveManager::load(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?load@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[592*8]
?load@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; SaveManager::import(const struct SaveInfo &, int);
?import@SaveManager@@QEAAXAEBUSaveInfo@@H@Z proc
jmp function_pointers[593*8]
?import@SaveManager@@QEAAXAEBUSaveInfo@@H@Z endp

; SaveManager::savesExist();
?savesExist@SaveManager@@QEAA_NXZ proc
jmp function_pointers[594*8]
?savesExist@SaveManager@@QEAA_NXZ endp

; SaveManager::saveExists(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?saveExists@SaveManager@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[595*8]
?saveExists@SaveManager@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::scanGames(class lektor<SaveInfo> &, bool);
?scanGames@SaveManager@@QEAAHAEAV?$lektor@USaveInfo@@@@_N@Z proc
jmp function_pointers[596*8]
?scanGames@SaveManager@@QEAAHAEAV?$lektor@USaveInfo@@@@_N@Z endp

; SaveManager::scanGames(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class lektor<SaveInfo> &, bool);
?scanGames@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$lektor@USaveInfo@@@@_N@Z proc
jmp function_pointers[597*8]
?scanGames@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$lektor@USaveInfo@@@@_N@Z endp

; SaveManager::loadInfo(struct SaveInfo &);
?loadInfo@SaveManager@@QEAA_NAEAUSaveInfo@@@Z proc
jmp function_pointers[598*8]
?loadInfo@SaveManager@@QEAA_NAEAUSaveInfo@@@Z endp

; SaveManager::checkVersion(const struct SaveInfo &);
?checkVersion@SaveManager@@QEAA_NAEBUSaveInfo@@@Z proc
jmp function_pointers[599*8]
?checkVersion@SaveManager@@QEAA_NAEBUSaveInfo@@@Z endp

; SaveManager::execute();
?execute@SaveManager@@QEAAXXZ proc
jmp function_pointers[600*8]
?execute@SaveManager@@QEAAXXZ endp

; SaveManager::getCurrentGame();
?getCurrentGame@SaveManager@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[601*8]
?getCurrentGame@SaveManager@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; SaveManager::versionCode(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?versionCode@SaveManager@@QEAAIAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[602*8]
?versionCode@SaveManager@@QEAAIAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; SaveManager::updateAutoSave();
?updateAutoSave@SaveManager@@QEAAXXZ proc
jmp function_pointers[603*8]
?updateAutoSave@SaveManager@@QEAAXXZ endp

; SaveManager::getSavePath();
?getSavePath@SaveManager@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[604*8]
?getSavePath@SaveManager@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; SaveManager::initialisePaths();
?initialisePaths@SaveManager@@QEAAXXZ proc
jmp function_pointers[605*8]
?initialisePaths@SaveManager@@QEAAXXZ endp

?_CONSTRUCTOR@SaveManager@@QEAAXXZ proc
?_CONSTRUCTOR@SaveManager@@QEAAXXZ endp

; SaveManager::SaveManager();
??0SaveManager@@QEAA@XZ proc
jmp function_pointers[606*8]
??0SaveManager@@QEAA@XZ endp

?_DESTRUCTOR@SaveManager@@QEAAXXZ proc
?_DESTRUCTOR@SaveManager@@QEAAXXZ endp

; SaveManager::~SaveManager();
??1SaveManager@@QEAA@XZ proc
jmp function_pointers[607*8]
??1SaveManager@@QEAA@XZ endp

; SaveManager::saveGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?saveGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[608*8]
?saveGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::loadGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?loadGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[609*8]
?loadGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::importGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, int);
?importGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z proc
jmp function_pointers[610*8]
?importGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z endp

; SaveManager::importPlayerBuildings(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?importPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[611*8]
?importPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::importOldPlayerBuildings(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?importOldPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[612*8]
?importOldPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

?_CONSTRUCTOR@hand@@QEAAXPEAVGameData@@W4itemType@@@Z proc
?_CONSTRUCTOR@hand@@QEAAXPEAVGameData@@W4itemType@@@Z endp

; hand::hand(class GameData *, enum itemType);
??0hand@@QEAA@PEAVGameData@@W4itemType@@@Z proc
jmp function_pointers[613*8]
??0hand@@QEAA@PEAVGameData@@W4itemType@@@Z endp

?_CONSTRUCTOR@hand@@QEAAXPEAVRootObjectBase@@@Z proc
?_CONSTRUCTOR@hand@@QEAAXPEAVRootObjectBase@@@Z endp

; hand::hand(class RootObjectBase *);
??0hand@@QEAA@PEAVRootObjectBase@@@Z proc
jmp function_pointers[614*8]
??0hand@@QEAA@PEAVRootObjectBase@@@Z endp

?_CONSTRUCTOR@hand@@QEAAXH@Z proc
?_CONSTRUCTOR@hand@@QEAAXH@Z endp

; hand::hand(const int);
??0hand@@QEAA@H@Z proc
jmp function_pointers[615*8]
??0hand@@QEAA@H@Z endp

?_CONSTRUCTOR@hand@@QEAAXAEBV1@@Z proc
?_CONSTRUCTOR@hand@@QEAAXAEBV1@@Z endp

; hand::hand(const class hand &);
??0hand@@QEAA@AEBV0@@Z proc
jmp function_pointers[616*8]
??0hand@@QEAA@AEBV0@@Z endp

?_CONSTRUCTOR@hand@@QEAAXIIW4itemType@@II@Z proc
?_CONSTRUCTOR@hand@@QEAAXIIW4itemType@@II@Z endp

; hand::hand(unsigned int, unsigned int, enum itemType, unsigned int, unsigned int);
??0hand@@QEAA@IIW4itemType@@II@Z proc
jmp function_pointers[617*8]
??0hand@@QEAA@IIW4itemType@@II@Z endp

?_CONSTRUCTOR@hand@@QEAAXXZ proc
?_CONSTRUCTOR@hand@@QEAAXXZ endp

; hand::hand();
??0hand@@QEAA@XZ proc
jmp function_pointers[618*8]
??0hand@@QEAA@XZ endp

; hand::toString();
?toString@hand@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[619*8]
?toString@hand@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; hand::fromString(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?fromString@hand@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[620*8]
?fromString@hand@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; hand::operator==(bool);
??8hand@@UEBA_N_N@Z proc
jmp function_pointers[621*8]
??8hand@@UEBA_N_N@Z endp

; hand::operator==(const class RootObjectBase *);
??8hand@@QEBA_NPEBVRootObjectBase@@@Z proc
jmp function_pointers[622*8]
??8hand@@QEBA_NPEBVRootObjectBase@@@Z endp

; hand::operator==(const class hand &);
??8hand@@UEBA_NAEBV0@@Z proc
jmp function_pointers[623*8]
??8hand@@UEBA_NAEBV0@@Z endp

; hand::operator!=(const class RootObjectBase *);
??9hand@@QEBA_NPEBVRootObjectBase@@@Z proc
jmp function_pointers[624*8]
??9hand@@QEBA_NPEBVRootObjectBase@@@Z endp

; hand::operator!=(const class hand &);
??9hand@@UEBA_NAEBV0@@Z proc
jmp function_pointers[625*8]
??9hand@@UEBA_NAEBV0@@Z endp

; hand::operator bool();
??Bhand@@QEBA_NXZ proc
jmp function_pointers[626*8]
??Bhand@@QEBA_NXZ endp

; hand::getCharacter();
?getCharacter@hand@@QEBAPEAVCharacter@@XZ proc
jmp function_pointers[627*8]
?getCharacter@hand@@QEBAPEAVCharacter@@XZ endp

; hand::getPlatoon();
?getPlatoon@hand@@QEBAPEAVPlatoon@@XZ proc
jmp function_pointers[628*8]
?getPlatoon@hand@@QEBAPEAVPlatoon@@XZ endp

; hand::getActivePlatoon();
?getActivePlatoon@hand@@QEBAPEAVActivePlatoon@@XZ proc
jmp function_pointers[629*8]
?getActivePlatoon@hand@@QEBAPEAVActivePlatoon@@XZ endp

; hand::getBuilding();
?getBuilding@hand@@QEBAPEAVBuilding@@XZ proc
jmp function_pointers[630*8]
?getBuilding@hand@@QEBAPEAVBuilding@@XZ endp

; hand::getItem();
?getItem@hand@@QEBAPEAVItem@@XZ proc
jmp function_pointers[631*8]
?getItem@hand@@QEBAPEAVItem@@XZ endp

; hand::getRootObject();
?getRootObject@hand@@QEBAPEAVRootObject@@XZ proc
jmp function_pointers[632*8]
?getRootObject@hand@@QEBAPEAVRootObject@@XZ endp

; hand::getRootObjectBase();
?getRootObjectBase@hand@@QEBAPEAVRootObjectBase@@XZ proc
jmp function_pointers[633*8]
?getRootObjectBase@hand@@QEBAPEAVRootObjectBase@@XZ endp

; hand::getTown();
?getTown@hand@@QEBAPEAVTownBase@@XZ proc
jmp function_pointers[634*8]
?getTown@hand@@QEBAPEAVTownBase@@XZ endp

; hand::debugWhatHappenedToMe();
?debugWhatHappenedToMe@hand@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[635*8]
?debugWhatHappenedToMe@hand@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; hand::operator<(const class hand &);
??Mhand@@QEBA_NAEBV0@@Z proc
jmp function_pointers[636*8]
??Mhand@@QEBA_NAEBV0@@Z endp

; hand::operator=(const class hand &);
??4hand@@QEAAAEAV0@AEBV0@@Z proc
jmp function_pointers[637*8]
??4hand@@QEAAAEAV0@AEBV0@@Z endp

; hand::operator=(class RootObjectBase *);
??4hand@@QEAAAEBV0@PEAVRootObjectBase@@@Z proc
jmp function_pointers[638*8]
??4hand@@QEAAAEBV0@PEAVRootObjectBase@@@Z endp

; hand::operator=(const int &);
??4hand@@QEAAAEBV0@AEBH@Z proc
jmp function_pointers[639*8]
??4hand@@QEAAAEBV0@AEBH@Z endp

; hand::setNull();
?setNull@hand@@QEAAXXZ proc
jmp function_pointers[640*8]
?setNull@hand@@QEAAXXZ endp

; hand::isNull();
?isNull@hand@@QEBA_NXZ proc
jmp function_pointers[641*8]
?isNull@hand@@QEBA_NXZ endp

; hand::isValid();
?isValid@hand@@QEBA_NXZ proc
jmp function_pointers[642*8]
?isValid@hand@@QEBA_NXZ endp

; hand::canCastToRootObject();
?canCastToRootObject@hand@@QEBA_NXZ proc
jmp function_pointers[643*8]
?canCastToRootObject@hand@@QEBA_NXZ endp

; hand::squadMatch(const class hand &);
?squadMatch@hand@@QEBA_NAEBV1@@Z proc
jmp function_pointers[644*8]
?squadMatch@hand@@QEBA_NAEBV1@@Z endp

; static_functions::showErrorMessage();
?showErrorMessage@@YAXXZ proc
jmp function_pointers[645*8]
?showErrorMessage@@YAXXZ endp

; static_functions::modMedicalSkill(float, class Item *, float);
?modMedicalSkill@@YAMMPEAVItem@@M@Z proc
jmp function_pointers[646*8]
?modMedicalSkill@@YAMMPEAVItem@@M@Z endp

FUNC_END proc
FUNC_END endp

.data
PUBLIC function_pointers
function_pointers QWORD 647 DUP(0)

.const
PUBLIC FUNCTION_SIZE, FUNCTION_BUFF_LENGTH, FUNCTION_ERROR
FUNCTION_SIZE DWORD (FUNC_SECOND - FUNC_BEGIN)
FUNCTION_BUFF_LENGTH DWORD (LENGTHOF function_pointers)
; FUNCTION_BLOCK_EXPECTED_SIZE DWORD ((LENGTHOF function_pointers) * (FUNC_SECOND - FUNC_BEGIN))
; FUNCTION_BLOCK_ACTUAL_SIZE DWORD (FUNC_END - FUNC_BEGIN)
FUNCTION_ERROR DWORD ((FUNC_END - FUNC_BEGIN) - ((LENGTHOF function_pointers) * (FUNC_SECOND - FUNC_BEGIN)))

END
