#pragma once

#ifdef AB_PLATFORM_WINDOWS

extern Amber::Application* Amber::CreateApplication();

int main(int argc, char** argv)
{
	printf("Amber Engine Start\n");
	auto app = Amber::CreateApplication();
	app->Run();
	delete app;
}

#endif