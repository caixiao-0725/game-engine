#pragma once
#include "core.h"
#include "cngine/Events/Event.h"
#include "Window.h"
#include "cngine/Events/ApplicationEvent.h"

#include "cngine/Core/LayerStack.h"
#include "cngine/ImGui/ImGuiLayer.h"

#include "cngine/Core/Timestep.h"

namespace Cngine {


	class Application
	{
	public:
		Application(const std::string& name = "Hazel App");
		virtual ~Application();

		void Run();

		void Close();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);


		inline Window& GetWindow() { return *m_Window; }

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
