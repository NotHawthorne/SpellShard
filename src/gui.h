#include"storage.h"
#include "mesh.h"

#define IM_ARRAYSIZE(_ARR)          ((int)(sizeof(_ARR)/sizeof(*_ARR)))

int gui_id = 1;
ImGuiWindowFlags staticflags = 
	ImGuiWindowFlags_NoResize         |
	ImGuiWindowFlags_NoMove           |
	ImGuiWindowFlags_NoScrollbar      |
	ImGuiWindowFlags_NoScrollWithMouse|
	ImGuiWindowFlags_NoCollapse       ;

int dis_x;
int dis_y;
ImVec2 center;

void CreateLoginMenu()
{
	static char uname[64]             = ""; 
	static char pass[64]              = "";  
	ImGui::SetNextWindowPos             (ImVec2(dis_x/2-(dis_x/8), dis_y/2-(dis_y/15)));
	ImGui::SetNextWindowSize            (ImVec2(dis_x/4, dis_y/4-(dis_y/9)));
	ImGui::Begin                        ("Login", NULL, staticflags);
	ImGui::InputText                    ("Username", uname, sizeof(uname));
	ImGui::InputText                    ("Password", pass,  sizeof(pass ));
    if (ImGui::Button("Authenticate")) 
	{
		std::vector<std::string>        vec;
		vec.push_back                   (uname); 
		vec.push_back                   (pass);
		Send                            (MSG_LOGIN_RESPONSE, vec);  Receive();
		if (Handle(buf)=="success")
		{
			Send                        (MSG_CHARACTER_LIST, vec); Receive();
			gui_id                    = 2;
		}
		closesocket(s);
	}
    ImGui::End();
}

void PopulateCharacterList(std::vector<std::string> list)  //MAKE LISTBOX
{
	const char* listbox_items[128];
	std::string end_endtext;

	map<int, string> rstrings         = racestrings.getList();
	map<int, string> cstrings         = classstrings.getList();

	std::vector<std::string> constrings;
	int its = 0;

	ImGui::Begin                        ("Character Selection");
	std::vector<std::string>::iterator  it;
	std::vector<std::string>::iterator  it2;
	for (it = list.begin(); it!=list.end(); ++it)
	{
		std::vector<std::string> strs = split(*it, '/');
		int race                      = std::stoi(strs[2]);
		int c_class                   = std::stoi(strs[3]);
		end_endtext                   = strs[0] + " (L." + strs[1] + " " + rstrings[race] + " " + cstrings[c_class] + ")";
		constrings.push_back(end_endtext);
	}
	for (it2 = constrings.begin(); it2!=constrings.end(); ++it2)
	{
		listbox_items[its] = (*it2).c_str();
		its++;
	}
    static int listbox_item_current = 1;
    ImGui::ListBox("", &listbox_item_current, listbox_items, its, 4);
	/*if (ImGui::IsItemHovered())
		ImGui::SetTooltip("Press Space to toggle");*/ //TODO: Have level/race/class data display on hover

	if(ImGui::Button("Login"))
	{
		Model m = loadModelFromFile("C:\\SpellShard\\imgui\\examples\\mesh\\cube.obj");
		render(m);
	}

	ImGui::End();
}

void CreateCharacterWindow()
{
	PopulateCharacterList               (HandleV(buf));
}

void ShowMenu()
{
	ImGuiIO& io = ImGui::GetIO();
	dis_x = io.DisplaySize.x;
	dis_y = io.DisplaySize.y;
	center = ImVec2(io.DisplaySize.x/2, io.DisplaySize.y/2);
	if (gui_id==1)
	{
		CreateLoginMenu();
	}
	if (gui_id==2)
	{
		CreateCharacterWindow();
	}
}