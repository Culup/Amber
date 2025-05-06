#pragma once

#ifdef AB_PLATFORM_WINDOWS

extern Amber::Application* Amber::CreateApplication();

int main(int argc, char** argv)
{
	Amber::Log::Init();
	AB_CORE_WARN("Initialized Log!");
	int a = 5;
	AB_INFO("Hello! Var={0}", a);

	auto app = Amber::CreateApplication();
	app->Run();
	delete app;
}

#endif