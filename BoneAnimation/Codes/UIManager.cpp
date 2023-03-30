#include "UIManager.h"
#include "..\imgui\imgui_impl_glfw.h"
#include "..\imgui\imgui_impl_opengl3.h"
#include "OpenGLDevice.h"
#include "Define.h"
#include "DiceMaster.h"
#include "iPhysicsWorld.h"

#include <sstream>
#include <iomanip>

SINGLETON_FUNCTION(UIManager)
USING(Engine)
USING(ImGui)
USING(std)

UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}

// Call instead of destructor to manage class internal data
void UIManager::Destroy()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	DestroyContext();
}

// Basic Render Function
void UIManager::RenderUI()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	NewFrame();

	//ImVec2 screen = ImVec2((_float)COpenGLDevice::GetInstance()->GetWidthSize(), (_float)COpenGLDevice::GetInstance()->GetHeightSize());
	ImVec2 screen = ImVec2(320.f, 470.f);
	SetNextWindowPos(ImVec2(0.f, 0.f));
	SetNextWindowSize(screen);
	if (Begin("UI", (bool*)0,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoTitleBar))
	{
		Text("User input options");
		Separator();

		Text("How to move the player:");
		Text("1. \"Click\" the tile to set a goal");
		Text("2. Press \"F1\" to move the player");
		Text("3. The player will move with Run animation");
		Separator();

		Text("F2 : Toggle Camera mode");
		Text("     (Free <-> Follow)");
		Text("F3 : Toggle Animation Blending Mode");
		Separator();

		Text("* Multiple Animations");
		Text("1 : Walk");
		Text("2 : Run");
		Text("3 : Attack 1");
		Text("4 : Attack 2");
		Text("5 : Grab");
		Text("6 : Pick up");
		Text("7 : Hurt");
		Text("8 : Death");
		Text("Not pressing : Idle");
		Separator();
		
		Text("* Debug");
		Text("0 : Color vertices according to their");
		Text("    assigned bones");
		Separator();

		Text("* Camera (Only for free mode)");
		Text("WASD / QE : Move / Rotate Camera");
		Text("Mouse Wheel Drag : Zoom In/Out");
	}
	End();

	Render();
	ImGui_ImplOpenGL3_RenderDrawData(GetDrawData());
}

// Initialize
RESULT UIManager::Ready(iPhysicsWorld* pWorld)
{
	IMGUI_CHECKVERSION();
	CreateContext();
	ImGuiIO& io = GetIO();

	if (!ImGui_ImplGlfw_InitForOpenGL(COpenGLDevice::GetInstance()->GetWindow(), true) ||
		!ImGui_ImplOpenGL3_Init("#version 460"))
		return PK_ERROR_IMGUI;
	StyleColorsDark();

	m_pPWorld = pWorld;

	return PK_NOERROR;
}