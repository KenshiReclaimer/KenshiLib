
.code

; forwarders

FUNC_BEGIN proc
FUNC_BEGIN endp

?_CONSTRUCTOR@CharacterHuman@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z proc
?_CONSTRUCTOR@CharacterHuman@@QEAAXPEAVGameData@@PEAVFaction@@Vhand@@@Z endp

; CharacterHuman::CharacterHuman(class GameData *, class Faction *, class hand);
??0CharacterHuman@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z proc
jmp function_pointers[0*8]
??0CharacterHuman@@QEAA@PEAVGameData@@PEAVFaction@@Vhand@@@Z endp

FUNC_SECOND proc
FUNC_SECOND endp

?_DESTRUCTOR@CharacterHuman@@QEAAXXZ proc
?_DESTRUCTOR@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::~CharacterHuman();
??1CharacterHuman@@UEAA@XZ proc
jmp function_pointers[1*8]
??1CharacterHuman@@UEAA@XZ endp

; CharacterHuman::isHuman();
?isHuman@CharacterHuman@@UEAAPEAV1@XZ proc
jmp function_pointers[2*8]
?isHuman@CharacterHuman@@UEAAPEAV1@XZ endp

; CharacterHuman::drawWeapon(class Item *, class std::basic_string<char,std::char_traits<char>,std::allocator<char> >);
?drawWeapon@CharacterHuman@@UEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[3*8]
?drawWeapon@CharacterHuman@@UEAA_NPEAVItem@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; CharacterHuman::sheatheWeapon();
?sheatheWeapon@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[4*8]
?sheatheWeapon@CharacterHuman@@UEAAXXZ endp

; CharacterHuman::getCurrentWeapon();
?getCurrentWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ proc
jmp function_pointers[5*8]
?getCurrentWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ endp

; CharacterHuman::getThePreferredWeapon();
?getThePreferredWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ proc
jmp function_pointers[6*8]
?getThePreferredWeapon@CharacterHuman@@UEAAPEAVWeapon@@XZ endp

; CharacterHuman::getRangedWeapon();
?getRangedWeapon@CharacterHuman@@UEAAPEAVCrossbow@@XZ proc
jmp function_pointers[7*8]
?getRangedWeapon@CharacterHuman@@UEAAPEAVCrossbow@@XZ endp

; CharacterHuman::serialise(class GameDataContainer *, class GameData *, class PosRotPair *);
?serialise@CharacterHuman@@UEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z proc
jmp function_pointers[8*8]
?serialise@CharacterHuman@@UEAA?AVGameSaveState@@PEAVGameDataContainer@@PEAVGameData@@PEAVPosRotPair@@@Z endp

; CharacterHuman::loadFromSerialise(class GameSaveState *);
?loadFromSerialise@CharacterHuman@@UEAAXPEAVGameSaveState@@@Z proc
jmp function_pointers[9*8]
?loadFromSerialise@CharacterHuman@@UEAAXPEAVGameSaveState@@@Z endp

; CharacterHuman::giveBirth(class GameDataCopyStandalone *, const class Ogre::Vector3 &, const class Ogre::Quaternion &, class GameSaveState *, class ActivePlatoon *, class Faction *);
?giveBirth@CharacterHuman@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z proc
jmp function_pointers[10*8]
?giveBirth@CharacterHuman@@UEAA_NPEAVGameDataCopyStandalone@@AEBVVector3@Ogre@@AEBVQuaternion@4@PEAVGameSaveState@@PEAVActivePlatoon@@PEAVFaction@@@Z endp

; CharacterHuman::setupInventorySections(class GameSaveState *);
?setupInventorySections@CharacterHuman@@UEAA_NPEAVGameSaveState@@@Z proc
jmp function_pointers[11*8]
?setupInventorySections@CharacterHuman@@UEAA_NPEAVGameSaveState@@@Z endp

; CharacterHuman::validateInventorySections();
?validateInventorySections@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[12*8]
?validateInventorySections@CharacterHuman@@UEAAXXZ endp

; CharacterHuman::setupAudio();
?setupAudio@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[13*8]
?setupAudio@CharacterHuman@@UEAAXXZ endp

; CharacterHuman::shaveHead(bool);
?shaveHead@CharacterHuman@@QEAAX_N@Z proc
jmp function_pointers[14*8]
?shaveHead@CharacterHuman@@QEAAX_N@Z endp

; CharacterHuman::isHeadShaven();
?isHeadShaven@CharacterHuman@@UEBA_NXZ proc
jmp function_pointers[15*8]
?isHeadShaven@CharacterHuman@@UEBA_NXZ endp

; CharacterHuman::createAnimationClass();
?createAnimationClass@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[16*8]
?createAnimationClass@CharacterHuman@@UEAAXXZ endp

; CharacterHuman::dropItem(class RootObject *);
?dropItem@CharacterHuman@@UEAAXPEAVRootObject@@@Z proc
jmp function_pointers[17*8]
?dropItem@CharacterHuman@@UEAAXPEAVRootObject@@@Z endp

; CharacterHuman::dropWeaponInHands();
?dropWeaponInHands@CharacterHuman@@QEAAXXZ proc
jmp function_pointers[18*8]
?dropWeaponInHands@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::dropWeaponInHandsFake();
?dropWeaponInHandsFake@CharacterHuman@@QEAAXXZ proc
jmp function_pointers[19*8]
?dropWeaponInHandsFake@CharacterHuman@@QEAAXXZ endp

; CharacterHuman::unequipItem(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Item *);
?unequipItem@CharacterHuman@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z proc
jmp function_pointers[20*8]
?unequipItem@CharacterHuman@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVItem@@@Z endp

; CharacterHuman::weatherUpdate(float);
?weatherUpdate@CharacterHuman@@UEAAXM@Z proc
jmp function_pointers[21*8]
?weatherUpdate@CharacterHuman@@UEAAXM@Z endp

; CharacterHuman::leaveSheathEquipped(class std::basic_string<char,std::char_traits<char>,std::allocator<char> >, int);
?leaveSheathEquipped@CharacterHuman@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z proc
jmp function_pointers[22*8]
?leaveSheathEquipped@CharacterHuman@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z endp

; CharacterHuman::postRagdollCallback(bool, enum RagdollPart::Enum);
?postRagdollCallback@CharacterHuman@@UEAAX_NW4Enum@RagdollPart@@@Z proc
jmp function_pointers[23*8]
?postRagdollCallback@CharacterHuman@@UEAAX_NW4Enum@RagdollPart@@@Z endp

; CharacterHuman::reCalculateNaturalWeapon();
?reCalculateNaturalWeapon@CharacterHuman@@UEAAXXZ proc
jmp function_pointers[24*8]
?reCalculateNaturalWeapon@CharacterHuman@@UEAAXXZ endp

?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXAEBV01@@Z proc
?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXAEBV01@@Z endp

; GameWorld::SysMessage::SysMessage(const class GameWorld::SysMessage &);
??0SysMessage@GameWorld@@QEAA@AEBV01@@Z proc
jmp function_pointers[25*8]
??0SysMessage@GameWorld@@QEAA@AEBV01@@Z endp

?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXW4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z proc
?_CONSTRUCTOR@SysMessage@GameWorld@@QEAAXW4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z endp

; GameWorld::SysMessage::SysMessage(enum GameWorld::SysMessageEnum, const class hand &, const class hand &, bool, float, void *);
??0SysMessage@GameWorld@@QEAA@W4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z proc
jmp function_pointers[26*8]
??0SysMessage@GameWorld@@QEAA@W4SysMessageEnum@1@AEBVhand@@1_NMPEAX@Z endp

; GameWorld::SysMessage::operator==(const class GameWorld::SysMessage &);
??8SysMessage@GameWorld@@QEBA_NAEBV01@@Z proc
jmp function_pointers[27*8]
??8SysMessage@GameWorld@@QEBA_NAEBV01@@Z endp

; GameWorld::justLoadFactionRelations(class GameDataManager *);
?justLoadFactionRelations@GameWorld@@QEAAXPEAVGameDataManager@@@Z proc
jmp function_pointers[28*8]
?justLoadFactionRelations@GameWorld@@QEAAXPEAVGameDataManager@@@Z endp

; GameWorld::startUpThreads();
?startUpThreads@GameWorld@@QEAA_NXZ proc
jmp function_pointers[29*8]
?startUpThreads@GameWorld@@QEAA_NXZ endp

?_CONSTRUCTOR@GameWorld@@QEAAXXZ proc
?_CONSTRUCTOR@GameWorld@@QEAAXXZ endp

; GameWorld::GameWorld();
??0GameWorld@@QEAA@XZ proc
jmp function_pointers[30*8]
??0GameWorld@@QEAA@XZ endp

?_DESTRUCTOR@GameWorld@@QEAAXXZ proc
?_DESTRUCTOR@GameWorld@@QEAAXXZ endp

; GameWorld::~GameWorld();
??1GameWorld@@QEAA@XZ proc
jmp function_pointers[31*8]
??1GameWorld@@QEAA@XZ endp

; GameWorld::start(class RendererT *);
?start@GameWorld@@QEAA_NPEAVRendererT@@@Z proc
jmp function_pointers[32*8]
?start@GameWorld@@QEAA_NPEAVRendererT@@@Z endp

; GameWorld::resetGame();
?resetGame@GameWorld@@QEAAXXZ proc
jmp function_pointers[33*8]
?resetGame@GameWorld@@QEAAXXZ endp

; GameWorld::_clearAndDestroyGameWorldStuff();
?_clearAndDestroyGameWorldStuff@GameWorld@@QEAAXXZ proc
jmp function_pointers[34*8]
?_clearAndDestroyGameWorldStuff@GameWorld@@QEAAXXZ endp

; GameWorld::initialisation();
?initialisation@GameWorld@@QEAA_NXZ proc
jmp function_pointers[35*8]
?initialisation@GameWorld@@QEAA_NXZ endp

; GameWorld::initialisationGameData();
?initialisationGameData@GameWorld@@QEAA_NXZ proc
jmp function_pointers[36*8]
?initialisationGameData@GameWorld@@QEAA_NXZ endp

; GameWorld::dailyUpdates();
?dailyUpdates@GameWorld@@QEAAXXZ proc
jmp function_pointers[37*8]
?dailyUpdates@GameWorld@@QEAAXXZ endp

; GameWorld::initialiseNewGameWorld(class GameDataManager *);
?initialiseNewGameWorld@GameWorld@@QEAAXPEAVGameDataManager@@@Z proc
jmp function_pointers[38*8]
?initialiseNewGameWorld@GameWorld@@QEAAXPEAVGameDataManager@@@Z endp

; GameWorld::errorToLogReleaseMode(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?errorToLogReleaseMode@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[39*8]
?errorToLogReleaseMode@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::errorD(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?errorD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[40*8]
?errorD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::logToSave(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?logToSave@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[41*8]
?logToSave@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::log(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?log@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[42*8]
?log@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::logDebug(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[43*8]
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; GameWorld::logDebug(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[44*8]
?logDebug@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::destroy(class Ogre::MovableObject *);
?destroy@GameWorld@@QEAAXPEAVMovableObject@Ogre@@@Z proc
jmp function_pointers[45*8]
?destroy@GameWorld@@QEAAXPEAVMovableObject@Ogre@@@Z endp

; GameWorld::destroy(class AttachedEntity *);
?destroy@GameWorld@@QEAAXPEAVAttachedEntity@@@Z proc
jmp function_pointers[46*8]
?destroy@GameWorld@@QEAAXPEAVAttachedEntity@@@Z endp

; GameWorld::destroy(class TownBuildingsManager *);
?destroy@GameWorld@@QEAAXPEAVTownBuildingsManager@@@Z proc
jmp function_pointers[47*8]
?destroy@GameWorld@@QEAAXPEAVTownBuildingsManager@@@Z endp

; GameWorld::destroy(class NestBatcher *);
?destroy@GameWorld@@QEAAXPEAVNestBatcher@@@Z proc
jmp function_pointers[48*8]
?destroy@GameWorld@@QEAAXPEAVNestBatcher@@@Z endp

; GameWorld::destroy(class RootObject *, bool, const char *);
?destroy@GameWorld@@QEAA_NPEAVRootObject@@_NPEBD@Z proc
jmp function_pointers[49*8]
?destroy@GameWorld@@QEAA_NPEAVRootObject@@_NPEBD@Z endp

; GameWorld::destroy(class GameData *);
?destroy@GameWorld@@QEAAXPEAVGameData@@@Z proc
jmp function_pointers[50*8]
?destroy@GameWorld@@QEAAXPEAVGameData@@@Z endp

; GameWorld::getIsInKillList(class RootObject *);
?getIsInKillList@GameWorld@@QEAA_NPEAVRootObject@@@Z proc
jmp function_pointers[51*8]
?getIsInKillList@GameWorld@@QEAA_NPEAVRootObject@@@Z endp

; GameWorld::flushKillList();
?flushKillList@GameWorld@@QEAAXXZ proc
jmp function_pointers[52*8]
?flushKillList@GameWorld@@QEAAXXZ endp

; GameWorld::dynamicDestroyBuilding(const class hand &);
?dynamicDestroyBuilding@GameWorld@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[53*8]
?dynamicDestroyBuilding@GameWorld@@QEAAXAEBVhand@@@Z endp

; GameWorld::allThreadQueuesAreClear();
?allThreadQueuesAreClear@GameWorld@@QEAA_NXZ proc
jmp function_pointers[54*8]
?allThreadQueuesAreClear@GameWorld@@QEAA_NXZ endp

; GameWorld::initBaseMods();
?initBaseMods@GameWorld@@QEAAXXZ proc
jmp function_pointers[55*8]
?initBaseMods@GameWorld@@QEAAXXZ endp

; GameWorld::initModsList();
?initModsList@GameWorld@@QEAAXXZ proc
jmp function_pointers[56*8]
?initModsList@GameWorld@@QEAAXXZ endp

; GameWorld::getModsListFromConfig();
?getModsListFromConfig@GameWorld@@QEAA?AV?$lektor@PEAVModInfo@@@@XZ proc
jmp function_pointers[57*8]
?getModsListFromConfig@GameWorld@@QEAA?AV?$lektor@PEAVModInfo@@@@XZ endp

; GameWorld::getAllModsList();
?getAllModsList@GameWorld@@QEBAAEBV?$lektor@PEAVModInfo@@@@XZ proc
jmp function_pointers[58*8]
?getAllModsList@GameWorld@@QEBAAEBV?$lektor@PEAVModInfo@@@@XZ endp

; GameWorld::getModIndex(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getModIndex@GameWorld@@QEBAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[59*8]
?getModIndex@GameWorld@@QEBAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; GameWorld::getModLeveldataFolder(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?getModLeveldataFolder@GameWorld@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z proc
jmp function_pointers[60*8]
?getModLeveldataFolder@GameWorld@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z endp

; GameWorld::getObjectsWithinSphere(class lektor<RootObject *> &, const class Ogre::Vector3 &, float, enum itemType, int, class RootObject *);
?getObjectsWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MW4itemType@@HPEAVRootObject@@@Z proc
jmp function_pointers[61*8]
?getObjectsWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MW4itemType@@HPEAVRootObject@@@Z endp

; GameWorld::getCharactersWithinSphere(class lektor<RootObject *> &, const class Ogre::Vector3 &, float, float, float, int, int, class RootObject *);
?getCharactersWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MMMHHPEAVRootObject@@@Z proc
jmp function_pointers[62*8]
?getCharactersWithinSphere@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@MMMHHPEAVRootObject@@@Z endp

; GameWorld::getObjectsWithinBox(class lektor<RootObject *> &, const class Ogre::Vector3 &, const class Ogre::Vector3 &, const class Ogre::Quaternion &, enum itemType, int, class RootObject *);
?getObjectsWithinBox@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@1AEBVQuaternion@4@W4itemType@@HPEAVRootObject@@@Z proc
jmp function_pointers[63*8]
?getObjectsWithinBox@GameWorld@@QEAAXAEAV?$lektor@PEAVRootObject@@@@AEBVVector3@Ogre@@1AEBVQuaternion@4@W4itemType@@HPEAVRootObject@@@Z endp

; GameWorld::buildingIntersectionTestCapsule(const class Ogre::Vector3 &, float, float, class RootObject *);
?buildingIntersectionTestCapsule@GameWorld@@QEAA_NAEBVVector3@Ogre@@MMPEAVRootObject@@@Z proc
jmp function_pointers[64*8]
?buildingIntersectionTestCapsule@GameWorld@@QEAA_NAEBVVector3@Ogre@@MMPEAVRootObject@@@Z endp

; GameWorld::getLightLevel(const class Ogre::Vector3 &, int, bool);
?getLightLevel@GameWorld@@QEBAMAEBVVector3@Ogre@@H_N@Z proc
jmp function_pointers[65*8]
?getLightLevel@GameWorld@@QEBAMAEBVVector3@Ogre@@H_N@Z endp

; GameWorld::populateMapArea_nonPermanent(class ZoneMap *, int, bool);
?populateMapArea_nonPermanent@GameWorld@@QEAAXPEAVZoneMap@@H_N@Z proc
jmp function_pointers[66*8]
?populateMapArea_nonPermanent@GameWorld@@QEAAXPEAVZoneMap@@H_N@Z endp

; GameWorld::findValidSpawnPos(class Ogre::Vector3 &, const class Ogre::Vector3 &);
?findValidSpawnPos@GameWorld@@QEAA_NAEAVVector3@Ogre@@AEBV23@@Z proc
jmp function_pointers[67*8]
?findValidSpawnPos@GameWorld@@QEAA_NAEAVVector3@Ogre@@AEBV23@@Z endp

; GameWorld::togglePause(bool);
?togglePause@GameWorld@@QEAAX_N@Z proc
jmp function_pointers[68*8]
?togglePause@GameWorld@@QEAAX_N@Z endp

; GameWorld::getFrameSpeedMultiplier();
?getFrameSpeedMultiplier@GameWorld@@QEBAMXZ proc
jmp function_pointers[69*8]
?getFrameSpeedMultiplier@GameWorld@@QEBAMXZ endp

; GameWorld::setFrameSpeedMultiplier(float);
?setFrameSpeedMultiplier@GameWorld@@QEAAXM@Z proc
jmp function_pointers[70*8]
?setFrameSpeedMultiplier@GameWorld@@QEAAXM@Z endp

; GameWorld::setGameSpeed(float, bool);
?setGameSpeed@GameWorld@@QEAAXM_N@Z proc
jmp function_pointers[71*8]
?setGameSpeed@GameWorld@@QEAAXM_N@Z endp

; GameWorld::userPause(bool);
?userPause@GameWorld@@QEAAX_N@Z proc
jmp function_pointers[72*8]
?userPause@GameWorld@@QEAAX_N@Z endp

; GameWorld::isPaused();
?isPaused@GameWorld@@QEBA_NXZ proc
jmp function_pointers[73*8]
?isPaused@GameWorld@@QEBA_NXZ endp

; GameWorld::getCameraCenter();
?getCameraCenter@GameWorld@@QEBA?BVVector3@Ogre@@XZ proc
jmp function_pointers[74*8]
?getCameraCenter@GameWorld@@QEBA?BVVector3@Ogre@@XZ endp

; GameWorld::getCameraPos();
?getCameraPos@GameWorld@@QEBA?BVVector3@Ogre@@XZ proc
jmp function_pointers[75*8]
?getCameraPos@GameWorld@@QEBA?BVVector3@Ogre@@XZ endp

; GameWorld::fixNaNPosition(class Ogre::Vector3 &);
?fixNaNPosition@GameWorld@@QEBA_NAEAVVector3@Ogre@@@Z proc
jmp function_pointers[76*8]
?fixNaNPosition@GameWorld@@QEBA_NAEAVVector3@Ogre@@@Z endp

; GameWorld::getWindSpeed(const class Ogre::Vector3 &);
?getWindSpeed@GameWorld@@QEBAMAEBVVector3@Ogre@@@Z proc
jmp function_pointers[77*8]
?getWindSpeed@GameWorld@@QEBAMAEBVVector3@Ogre@@@Z endp

; GameWorld::isLoadingFromASaveGame();
?isLoadingFromASaveGame@GameWorld@@QEAA_NXZ proc
jmp function_pointers[78*8]
?isLoadingFromASaveGame@GameWorld@@QEAA_NXZ endp

; GameWorld::addToUpdateListMain(class Character *);
?addToUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z proc
jmp function_pointers[79*8]
?addToUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z endp

; GameWorld::removeFromUpdateListMain(class Character *);
?removeFromUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z proc
jmp function_pointers[80*8]
?removeFromUpdateListMain@GameWorld@@QEAAXPEAVCharacter@@@Z endp

; GameWorld::getCharacterUpdateList();
?getCharacterUpdateList@GameWorld@@QEBAAEBV?$unordered_set@PEAVCharacter@@U?$hash@PEAVCharacter@@@boost@@U?$equal_to@PEAVCharacter@@@std@@V?$STLAllocator@PEAVCharacter@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@XZ proc
jmp function_pointers[81*8]
?getCharacterUpdateList@GameWorld@@QEBAAEBV?$unordered_set@PEAVCharacter@@U?$hash@PEAVCharacter@@@boost@@U?$equal_to@PEAVCharacter@@@std@@V?$STLAllocator@PEAVCharacter@@V?$CategorisedAllocPolicy@$0A@@Ogre@@@Ogre@@@unordered@boost@@XZ endp

; GameWorld::addToDeathParade(class Character *);
?addToDeathParade@GameWorld@@QEAAXPEAVCharacter@@@Z proc
jmp function_pointers[82*8]
?addToDeathParade@GameWorld@@QEAAXPEAVCharacter@@@Z endp

; GameWorld::removeFromDeathParade(class Character *);
?removeFromDeathParade@GameWorld@@QEAA_NPEAVCharacter@@@Z proc
jmp function_pointers[83*8]
?removeFromDeathParade@GameWorld@@QEAA_NPEAVCharacter@@@Z endp

; GameWorld::removeFromDeathParadeByPlatoon(class Platoon *);
?removeFromDeathParadeByPlatoon@GameWorld@@QEAAXPEAVPlatoon@@@Z proc
jmp function_pointers[84*8]
?removeFromDeathParadeByPlatoon@GameWorld@@QEAAXPEAVPlatoon@@@Z endp

; GameWorld::getFromDeathParade(const class hand &);
?getFromDeathParade@GameWorld@@QEAAPEAVCharacter@@AEBVhand@@@Z proc
jmp function_pointers[85*8]
?getFromDeathParade@GameWorld@@QEAAPEAVCharacter@@AEBVhand@@@Z endp

; GameWorld::hideContextMenu();
?hideContextMenu@GameWorld@@QEAAXXZ proc
jmp function_pointers[86*8]
?hideContextMenu@GameWorld@@QEAAXXZ endp

; GameWorld::showPlayerAMessage_withLog(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?showPlayerAMessage_withLog@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[87*8]
?showPlayerAMessage_withLog@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; GameWorld::showPlayerAMessage(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?showPlayerAMessage@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[88*8]
?showPlayerAMessage@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; GameWorld::showPlayerAMessageD(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?showPlayerAMessageD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[89*8]
?showPlayerAMessageD@GameWorld@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; GameWorld::playNotification(const char *);
?playNotification@GameWorld@@QEBAXPEBD@Z proc
jmp function_pointers[90*8]
?playNotification@GameWorld@@QEBAXPEBD@Z endp

; GameWorld::sysMessage(const class GameWorld::SysMessage &);
?sysMessage@GameWorld@@QEAAXAEBVSysMessage@1@@Z proc
jmp function_pointers[91*8]
?sysMessage@GameWorld@@QEAAXAEBVSysMessage@1@@Z endp

; GameWorld::sysMessageUrgent(const class GameWorld::SysMessage &);
?sysMessageUrgent@GameWorld@@QEAAXAEBVSysMessage@1@@Z proc
jmp function_pointers[92*8]
?sysMessageUrgent@GameWorld@@QEAAXAEBVSysMessage@1@@Z endp

; GameWorld::sysMessage_noDuplicates(const class GameWorld::SysMessage &);
?sysMessage_noDuplicates@GameWorld@@QEAAXAEBVSysMessage@1@@Z proc
jmp function_pointers[93*8]
?sysMessage_noDuplicates@GameWorld@@QEAAXAEBVSysMessage@1@@Z endp

; GameWorld::mainLoop_GPUSensitiveStuff(float);
?mainLoop_GPUSensitiveStuff@GameWorld@@UEAAXM@Z proc
jmp function_pointers[94*8]
?mainLoop_GPUSensitiveStuff@GameWorld@@UEAAXM@Z endp

; GameWorld::clearPortaitsUpdate();
?clearPortaitsUpdate@GameWorld@@QEAAXXZ proc
jmp function_pointers[95*8]
?clearPortaitsUpdate@GameWorld@@QEAAXXZ endp

; GameWorld::addPortraitUpdate(const class hand &);
?addPortraitUpdate@GameWorld@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[96*8]
?addPortraitUpdate@GameWorld@@QEAAXAEBVhand@@@Z endp

; GameWorld::removePortaitUpdate(const class hand &);
?removePortaitUpdate@GameWorld@@QEAAXAEBVhand@@@Z proc
jmp function_pointers[97*8]
?removePortaitUpdate@GameWorld@@QEAAXAEBVhand@@@Z endp

; GameWorld::processSysMessages();
?processSysMessages@GameWorld@@QEAAXXZ proc
jmp function_pointers[98*8]
?processSysMessages@GameWorld@@QEAAXXZ endp

; GameWorld::getCollisionGroupType(enum itemType, enum NxShapesType &, unsigned int &);
?getCollisionGroupType@GameWorld@@QEAAXW4itemType@@AEAW4NxShapesType@@AEAI@Z proc
jmp function_pointers[99*8]
?getCollisionGroupType@GameWorld@@QEAAXW4itemType@@AEAW4NxShapesType@@AEAI@Z endp

; GameWorld::destroyDeathParade();
?destroyDeathParade@GameWorld@@QEAAXXZ proc
jmp function_pointers[100*8]
?destroyDeathParade@GameWorld@@QEAAXXZ endp

; GameWorld::processKeys();
?processKeys@GameWorld@@QEAAXXZ proc
jmp function_pointers[101*8]
?processKeys@GameWorld@@QEAAXXZ endp

; GameWorld::processThreadMessages();
?processThreadMessages@GameWorld@@QEAAXXZ proc
jmp function_pointers[102*8]
?processThreadMessages@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdate();
?charsUpdate@GameWorld@@QEAAXXZ proc
jmp function_pointers[103*8]
?charsUpdate@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdateUT();
?charsUpdateUT@GameWorld@@QEAAXXZ proc
jmp function_pointers[104*8]
?charsUpdateUT@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdatePaused();
?charsUpdatePaused@GameWorld@@QEAAXXZ proc
jmp function_pointers[105*8]
?charsUpdatePaused@GameWorld@@QEAAXXZ endp

; GameWorld::charsUpdateDeathParade();
?charsUpdateDeathParade@GameWorld@@QEAAXXZ proc
jmp function_pointers[106*8]
?charsUpdateDeathParade@GameWorld@@QEAAXXZ endp

; GameWorld::threadSafeRagdollUpdates();
?threadSafeRagdollUpdates@GameWorld@@QEAAXXZ proc
jmp function_pointers[107*8]
?threadSafeRagdollUpdates@GameWorld@@QEAAXXZ endp

; GameWorld::AINonRenderThread();
?AINonRenderThread@GameWorld@@QEAAPEAVThreadWannabe@@XZ proc
jmp function_pointers[108*8]
?AINonRenderThread@GameWorld@@QEAAPEAVThreadWannabe@@XZ endp

; GameWorld::processAttachmentsKillList();
?processAttachmentsKillList@GameWorld@@QEAAXXZ proc
jmp function_pointers[109*8]
?processAttachmentsKillList@GameWorld@@QEAAXXZ endp

; GameWorld::processKillList(bool);
?processKillList@GameWorld@@QEAAX_N@Z proc
jmp function_pointers[110*8]
?processKillList@GameWorld@@QEAAX_N@Z endp

; GameWorld::processUpdateRemovalList();
?processUpdateRemovalList@GameWorld@@QEAAXXZ proc
jmp function_pointers[111*8]
?processUpdateRemovalList@GameWorld@@QEAAXXZ endp

; GameWorld::loadAllPlatoons();
?loadAllPlatoons@GameWorld@@QEAAXXZ proc
jmp function_pointers[112*8]
?loadAllPlatoons@GameWorld@@QEAAXXZ endp

; GameWorld::reCalculateFortificationInsideOutsideStateForAllCharacters();
?reCalculateFortificationInsideOutsideStateForAllCharacters@GameWorld@@QEAAXXZ proc
jmp function_pointers[113*8]
?reCalculateFortificationInsideOutsideStateForAllCharacters@GameWorld@@QEAAXXZ endp

; GameWorld::getTimeStamp();
?getTimeStamp@GameWorld@@QEAANXZ proc
jmp function_pointers[114*8]
?getTimeStamp@GameWorld@@QEAANXZ endp

; GameWorld::getTimeFromStamp(const class TimeOfDay &);
?getTimeFromStamp@GameWorld@@QEAA?AVTimeOfDay@@AEBV2@@Z proc
jmp function_pointers[115*8]
?getTimeFromStamp@GameWorld@@QEAA?AVTimeOfDay@@AEBV2@@Z endp

; GameWorld::getTimeFromStamp(double);
?getTimeFromStamp@GameWorld@@QEAAMN@Z proc
jmp function_pointers[116*8]
?getTimeFromStamp@GameWorld@@QEAAMN@Z endp

; GameWorld::getTimeFromStamp_inGameHours(double);
?getTimeFromStamp_inGameHours@GameWorld@@QEAAMN@Z proc
jmp function_pointers[117*8]
?getTimeFromStamp_inGameHours@GameWorld@@QEAAMN@Z endp

; GameWorld::getTimeStamp_inGameHours();
?getTimeStamp_inGameHours@GameWorld@@QEAA?AVTimeOfDay@@XZ proc
jmp function_pointers[118*8]
?getTimeStamp_inGameHours@GameWorld@@QEAA?AVTimeOfDay@@XZ endp

; GameWorld::getLengthOfHourInRealSeconds();
?getLengthOfHourInRealSeconds@GameWorld@@QEAAMXZ proc
jmp function_pointers[119*8]
?getLengthOfHourInRealSeconds@GameWorld@@QEAAMXZ endp

; SaveManager::getSingleton();
?getSingleton@SaveManager@@SAPEAV1@XZ proc
jmp function_pointers[120*8]
?getSingleton@SaveManager@@SAPEAV1@XZ endp

; SaveManager::isVisible();
?isVisible@SaveManager@@QEAAHXZ proc
jmp function_pointers[121*8]
?isVisible@SaveManager@@QEAAHXZ endp

; SaveManager::showSave();
?showSave@SaveManager@@QEAAXXZ proc
jmp function_pointers[122*8]
?showSave@SaveManager@@QEAAXXZ endp

; SaveManager::showLoad();
?showLoad@SaveManager@@QEAAXXZ proc
jmp function_pointers[123*8]
?showLoad@SaveManager@@QEAAXXZ endp

; SaveManager::showImport();
?showImport@SaveManager@@QEAAXXZ proc
jmp function_pointers[124*8]
?showImport@SaveManager@@QEAAXXZ endp

; SaveManager::hide();
?hide@SaveManager@@QEAAXXZ proc
jmp function_pointers[125*8]
?hide@SaveManager@@QEAAXXZ endp

; SaveManager::newGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?newGame@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[126*8]
?newGame@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; SaveManager::save(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool);
?save@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z proc
jmp function_pointers[127*8]
?save@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z endp

; SaveManager::load(const struct SaveInfo &, bool);
?load@SaveManager@@QEAAXAEBUSaveInfo@@_N@Z proc
jmp function_pointers[128*8]
?load@SaveManager@@QEAAXAEBUSaveInfo@@_N@Z endp

; SaveManager::load(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?load@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[129*8]
?load@SaveManager@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; SaveManager::import(const struct SaveInfo &, int);
?import@SaveManager@@QEAAXAEBUSaveInfo@@H@Z proc
jmp function_pointers[130*8]
?import@SaveManager@@QEAAXAEBUSaveInfo@@H@Z endp

; SaveManager::savesExist();
?savesExist@SaveManager@@QEAA_NXZ proc
jmp function_pointers[131*8]
?savesExist@SaveManager@@QEAA_NXZ endp

; SaveManager::saveExists(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?saveExists@SaveManager@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[132*8]
?saveExists@SaveManager@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::scanGames(class lektor<SaveInfo> &, bool);
?scanGames@SaveManager@@QEAAHAEAV?$lektor@USaveInfo@@@@_N@Z proc
jmp function_pointers[133*8]
?scanGames@SaveManager@@QEAAHAEAV?$lektor@USaveInfo@@@@_N@Z endp

; SaveManager::scanGames(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class lektor<SaveInfo> &, bool);
?scanGames@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$lektor@USaveInfo@@@@_N@Z proc
jmp function_pointers[134*8]
?scanGames@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$lektor@USaveInfo@@@@_N@Z endp

; SaveManager::loadInfo(struct SaveInfo &);
?loadInfo@SaveManager@@QEAA_NAEAUSaveInfo@@@Z proc
jmp function_pointers[135*8]
?loadInfo@SaveManager@@QEAA_NAEAUSaveInfo@@@Z endp

; SaveManager::checkVersion(const struct SaveInfo &);
?checkVersion@SaveManager@@QEAA_NAEBUSaveInfo@@@Z proc
jmp function_pointers[136*8]
?checkVersion@SaveManager@@QEAA_NAEBUSaveInfo@@@Z endp

; SaveManager::execute();
?execute@SaveManager@@QEAAXXZ proc
jmp function_pointers[137*8]
?execute@SaveManager@@QEAAXXZ endp

; SaveManager::getCurrentGame();
?getCurrentGame@SaveManager@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[138*8]
?getCurrentGame@SaveManager@@QEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; SaveManager::versionCode(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?versionCode@SaveManager@@QEAAIAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z proc
jmp function_pointers[139*8]
?versionCode@SaveManager@@QEAAIAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z endp

; SaveManager::updateAutoSave();
?updateAutoSave@SaveManager@@QEAAXXZ proc
jmp function_pointers[140*8]
?updateAutoSave@SaveManager@@QEAAXXZ endp

; SaveManager::getSavePath();
?getSavePath@SaveManager@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ proc
jmp function_pointers[141*8]
?getSavePath@SaveManager@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ endp

; SaveManager::initialisePaths();
?initialisePaths@SaveManager@@QEAAXXZ proc
jmp function_pointers[142*8]
?initialisePaths@SaveManager@@QEAAXXZ endp

?_CONSTRUCTOR@SaveManager@@QEAAXXZ proc
?_CONSTRUCTOR@SaveManager@@QEAAXXZ endp

; SaveManager::SaveManager();
??0SaveManager@@QEAA@XZ proc
jmp function_pointers[143*8]
??0SaveManager@@QEAA@XZ endp

?_DESTRUCTOR@SaveManager@@QEAAXXZ proc
?_DESTRUCTOR@SaveManager@@QEAAXXZ endp

; SaveManager::~SaveManager();
??1SaveManager@@QEAA@XZ proc
jmp function_pointers[144*8]
??1SaveManager@@QEAA@XZ endp

; SaveManager::saveGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?saveGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[145*8]
?saveGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::loadGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?loadGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[146*8]
?loadGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::importGame(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, int);
?importGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z proc
jmp function_pointers[147*8]
?importGame@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z endp

; SaveManager::importPlayerBuildings(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?importPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[148*8]
?importPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; SaveManager::importOldPlayerBuildings(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
?importOldPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z proc
jmp function_pointers[149*8]
?importOldPlayerBuildings@SaveManager@@QEAAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z endp

; static_functions::showErrorMessage();
?showErrorMessage@@YAXXZ proc
jmp function_pointers[150*8]
?showErrorMessage@@YAXXZ endp

; static_functions::modMedicalSkill(float, class Item *, float);
?modMedicalSkill@@YAMMPEAVItem@@M@Z proc
jmp function_pointers[151*8]
?modMedicalSkill@@YAMMPEAVItem@@M@Z endp

FUNC_END proc
FUNC_END endp

.data
PUBLIC function_pointers
function_pointers QWORD 152 DUP(0)

.const
PUBLIC FUNCTION_SIZE, FUNCTION_BUFF_LENGTH, FUNCTION_ERROR
FUNCTION_SIZE DWORD (FUNC_SECOND - FUNC_BEGIN)
FUNCTION_BUFF_LENGTH DWORD (LENGTHOF function_pointers)
; FUNCTION_BLOCK_EXPECTED_SIZE DWORD ((LENGTHOF function_pointers) * (FUNC_SECOND - FUNC_BEGIN))
; FUNCTION_BLOCK_ACTUAL_SIZE DWORD (FUNC_END - FUNC_BEGIN)
FUNCTION_ERROR DWORD ((FUNC_END - FUNC_BEGIN) - ((LENGTHOF function_pointers) * (FUNC_SECOND - FUNC_BEGIN)))

END
