#pragma once
#include "include.h"
#include "menu.h"

float rainbowspeed = 0.002f;
void SetupImGuiStyle()
{
	// Fork of Soft Cherry style from ImThemes
	ImGuiStyle& style = ImGui::GetStyle();

	style.WindowMinSize = ImVec2(160, 20);
	style.FramePadding = ImVec2(4, 2);
	style.ItemSpacing = ImVec2(6, 2);
	style.ItemInnerSpacing = ImVec2(6, 4);
	style.Alpha = 0.95f;
	style.WindowRounding = 4.0f;
	style.FrameRounding = 2.0f;
	style.IndentSpacing = 6.0f;
	style.ItemInnerSpacing = ImVec2(2, 4);
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = 16.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 16.0f;


	style.Colors[ImGuiCol_Text] = ImColor(255, 215, 0);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.15f, 0.90f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(255, 215, 0);
	style.Colors[ImGuiCol_CheckMark] = ImColor(255, 215, 0);
	style.Colors[ImGuiCol_SliderGrab] = ImColor(255, 215, 0, 140); //ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 215, 0);//ImVec4(0.08f, 0.50f, 0.72f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
	style.Colors[ImGuiCol_Separator] = style.Colors[ImGuiCol_Border];
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.41f, 0.42f, 0.44f, 1.00f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.29f, 0.30f, 0.31f, 0.67f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);

}


void MenuAndDestroy(ImGuiWindow& window) {


	// Call rainbow here!



	window.DrawList->PushClipRectFullScreen();
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
	SetupImGuiStyle();

	if (ShowMenu) {

		ImGui::SetNextWindowSize(ImVec2(480, 370));      
		ImGui::Begin(e("LACH E-Sports Internal"), nullptr, ImGuiWindowFlags_NoCollapse);
		static int tab;
		if (ImGui::Button(e("Aimbot"), ImVec2(77, 0)))
			tab = 0;
		ImGui::SameLine();
		if (ImGui::Button(e("Visuals"), ImVec2(77, 0)))
			tab = 1;
		ImGui::SameLine();
		if (ImGui::Button(e("Exploits"), ImVec2(77, 0)))
			tab = 2;
		if (tab == 0) {

			ImGui::BeginChild("##0", ImVec2(0, 0), true);
			ImGui::Checkbox(e("Memory Aim [Rage]"), &Settings::MemoryAim);
			ImGui::Checkbox(e("Soft Aim [Legit]"), &Settings::SoftAim);
			ImGui::SliderFloat(e("Soft Aim Smooth"), &Settings::aimspeed, 1, 100);
			ImGui::SliderFloat(e("FOV Size"), &FovSize, 30.0f, 3000.f);

			ImGui::EndChild();

		}
		else if (tab == 1)
		{

			if(ImGui::BeginChild("##1", ImVec2(0, 0), true)) {

				ImGui::Checkbox("Box ESP", &Settings::BoxESP);
				ImGui::Checkbox("Cornered Box ESP", &Settings::Box);
				ImGui::Checkbox("Skeleton ESP", &Settings::SkeletonESP);
				ImGui::Checkbox("Line ESP", &Settings::LinesESP);
				ImGui::Checkbox("Name ESP", &Settings::PlayerNameESP);
				ImGui::Checkbox("Distance ESP", &Settings::DistanceESP);
				ImGui::Checkbox("Level ESP", &Settings::LevelESP);
				ImGui::Checkbox("Kills ESP", &Settings::KillsESP);
				ImGui::Checkbox("Platform ESP", &Settings::PlatformESP);
				ImGui::Checkbox("Weapon ESP", &Settings::EnemyWeaponESP);
				ImGui::Checkbox("Chams", &Settings::Chams);
				ImGui::Checkbox("Aim Line", &Settings::aimini);
				ImGui::Checkbox("Item ESP [LAGGY]", &Settings::item);
			}ImGui::EndChild();

		}
		else if (tab == 2)
		{
			ImGui::BeginChild("##1", ImVec2(0, 0), true);
			ImGui::Checkbox("Projectile Bullet TP", &Settings::SniperTp);
			ImGui::Checkbox("Car Fly [BUGGY/RISKY]", &Settings::CarFly);
			ImGui::Checkbox("Sync Car Fly Camera Rotation", &Settings::SyncCameraRotation);
			ImGui::Checkbox("Car Kill [CAPS]", &Settings::VehicleTPE);
			ImGui::Checkbox("Airstuck [CAPS]", &Settings::airstuck);
			ImGui::Checkbox("Spin Bot", &Settings::Spinbot);
			ImGui::Checkbox("Instant Reload [BUGGY]", &Settings::instareload);
			ImGui::Checkbox("Double Pump", &Settings::doublepump);
			ImGui::Checkbox("No Bloom", &Settings::nobloom);
			ImGui::Checkbox("Infinite Fuel", &Settings::InfiniteFuel);
			ImGui::Checkbox("Invisibility", &Settings::Invisible);
			ImGui::Checkbox("Player Fly", &Settings::PlayerFly);
			ImGui::Checkbox("FOV Changer", &Settings::FovChanger);
			if (Settings::FovChanger)
				ImGui::SliderFloat("FOV Value", &Settings::FovChanger_Value, 0.0f, 180.0f);
			ImGui::Text("NOTE: Car Kill + Airstuck = CAR TP");
			ImGui::EndChild();
		}








		ImGui::End();
	}

	// Rainbow renders


	ImGui::Render();
}


