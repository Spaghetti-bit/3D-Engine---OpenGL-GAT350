#pragma once
#include "../Core/System.h"

namespace nc
{


	class InputSystem : public System
	{
	public:
		enum class eButtonState
		{
			IDLE,
			PRESSED,
			HELD,
			RELEASED

		};
	public:
		// Button Inputs
		eButtonState GetButtonState(int id);
		bool GetButtonDown(int id);
		bool GetPreviousButtonDown(int id);



		// Inherited via System
		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;




	protected:
		Uint8* m_keystate{ nullptr };
		Uint8* m_prevKeystate{ nullptr };
		int m_numKeys{ NULL };
	};
}