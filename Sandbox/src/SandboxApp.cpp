#include <Amber.h>

class ExampleLayer : public Amber::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		AB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Amber::Event& event) override
	{
		AB_TRACE("{0}", event);
	}

};

class Sandbox : public Amber::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}

};

Amber::Application* Amber::CreateApplication()
{
	return new Sandbox();
}