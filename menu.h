#pragma once
#pragma warning(disable : 4996)


#pragma warning(disable : 4996)




namespace PYGUI
{
	namespace Input
	{
		bool mouseDown[5];
		bool mouseDownAlready[256];

		bool keysDown[256];
		bool keysDownAlready[256];

		bool IsAnyMouseDown()
		{
			if (mouseDown[0]) return true;
			if (mouseDown[1]) return true;
			if (mouseDown[2]) return true;
			if (mouseDown[3]) return true;
			if (mouseDown[4]) return true;

			return false;
		}

		bool IsMouseClicked(int button, int element_id, bool repeat)
		{
			if (mouseDown[button])
			{
				if (!mouseDownAlready[element_id])
				{
					mouseDownAlready[element_id] = true;
					return true;
				}
				if (repeat)
					return true;
			}
			else
			{
				mouseDownAlready[element_id] = false;
			}
			return false;
		}
		bool IsKeyPressed(int key, bool repeat)
		{
			if (keysDown[key])
			{
				if (!keysDownAlready[key])
				{
					keysDownAlready[key] = true;
					return true;
				}
				if (repeat)
					return true;
			}
			else
			{
				keysDownAlready[key] = false;
			}
			return false;
		}

		void Handle()
		{
			if (itsjustaispoof(GetAsyncKeyState)(0x01))
				mouseDown[0] = true;
			else
				mouseDown[0] = false;
		}
	}
}
wchar_t* s2wc(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}
namespace Settings
{
	//Aim
	static bool aimini = 0;
	static bool MemoryAim = 0; //Done
	static bool SoftAim = 0; //
	static float aimspeed =  10;
	static bool pmemory = 0; //Done
	static bool SilentAim = 0; //Done
	static bool SniperTp = 0; //Done
	static bool VehicleTPE = 0; //Done
	static bool tpplayer = 0;
	static bool tpZipline = 0;
	int BoneTarget = 0;
	static int AimBone = 106;
	static float MemoryAimSmooth = 0; //Done

	static bool fov360 = 0; //Done
	static float FovCircle_Value = 430; //Done



	//Player ESP
	static bool BoxESP = 0; //Done
	static bool Box = 0; //Done
	static bool getboneid = 0; //Done
	static bool TeamCheck = 1;
	static int testcapi = 0;
	static bool speedhack = 0;
	static bool SkeletonESP = 0; //Done
	static bool LinesESP = 0; //Done
	static bool PlayerNameESP = 0; //Done
	static bool DistanceESP = 0; //Done
	static bool LevelESP = 0; //Done
	static bool KillsESP = 0; //Done
	static bool PlatformESP = 0; //Done
	static bool EnemyWeaponESP = 0; //Done
	static bool AmmoESP = 0; //Done
	static bool RadarESP = 0;
	static float RadarESPRange = 7000.f;
	static int RadarESPOpacity = 255;
	static bool DMRESP = 0;
	static bool Vehicle = 0;

	static bool Chest = 0;
	static bool Ammo = 0;
	static bool tpitem;


	
	//Exploits
	static bool NoSpread = 0; //Done
	static bool Chams = 0; //Done
	static bool Invisible = 0; //Done
	static bool InstantRevive = 0; //Done
	static bool AimWhileJumping = 0; //Done
	static bool resources = 0;
	static bool RapidFire = 0;
	static bool Zipline = 0;
	static bool Marker = 0;
	static bool item = 0;
	static float RapidFireValue = 0.001f;
	static bool FirstCamera = 0; //Done
	static bool InstantReload = 0; //Done
	static bool SpeedStuff = 0; //Done
	static float CustomSpeedStuff = 0; //Done
	static bool LocalPawnSpeed = 0; //Done
	static bool VehicleFly = 0;
	static float VehicleFlySpeed = 50;
	static bool VehicleTP = 0;
	static bool SyncCameraRotation = 0;
	static bool fovcircle = 0;

	//Fov Changer
	static bool FovChanger = 0; //Done
	static float FovChanger_Value = 100.f; //Done

	//Boat Speed
	static bool VehicleSpeed = 0;
	static float VehicleSpeedValue = 30.f;

	//Car Exploits
	static bool CarFly = 0; //Done
	static bool CarTpToPing = 0; //Done
	static bool CarTpToPlayer = 0; //Done
	static bool TP_Locations_Start = 0; //Done
	static int TP_Locations = 0; //Done


	static bool TPToAimingPlayer = 0; //Done

	static bool PlayerFly = 0; //Done
	static bool Spinbot = 0; //Done
	static bool InfiniteAmmo = 0; //Done
	static bool InfiniteFuel = 0; //Done
	static bool instareload = 0; //Done
	static bool doublepump = 0; //Done
	static bool nobloom = 0; //Done
	static bool airstuck = 0; //Done

	//Misc

	static float MaxESPDistance = 300; //Done
	static bool ShowFovCircle = true; //Done

	static bool PanicButtonFeature = true;
	static bool PanicButtonON = false;



}
int tabs = 0;
float FovSize = 150;
float inr;
float ing;
float inb;
float ino;

float outr;
float outg;
float outb;
float outo;
#define D2R(d) (d / 180.f) * M_PI
#define MAX_SEGMENTS 180
int myceilf(float num)
{
	int inum = (int)num;
	if (num == (float)inum) {
		return inum;
	}
	return inum + 1;
}