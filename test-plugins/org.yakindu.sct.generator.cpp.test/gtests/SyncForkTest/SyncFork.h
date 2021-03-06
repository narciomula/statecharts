
#ifndef SYNCFORK_H_
#define SYNCFORK_H_

#include "sc_types.h"
#include "StatemachineInterface.h"

/*! \file Header of the state machine 'SyncFork'.
*/

class SyncFork : public StatemachineInterface
{
	
	public:
		
		SyncFork();
		
		~SyncFork();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			main_region_A,
			main_region_B,
			main_region_B_r1_C1,
			main_region_B_r1_C2,
			main_region_B_r2_D1,
			main_region_B_r2_D2,
			SyncFork_last_state
		} SyncForkStates;
		
		//! Inner class for default interface scope.
		class DefaultSCI
		{
			
			public:
				/*! Raises the in event 'e' that is defined in the default interface scope. */
				void raise_e();
				
				/*! Raises the in event 'f' that is defined in the default interface scope. */
				void raise_f();
				
				
			private:
				friend class SyncFork;
				sc_boolean e_raised;
				sc_boolean f_raised;
		};
				
		
		/*! Returns an instance of the interface class 'DefaultSCI'. */
		DefaultSCI* getDefaultSCI();
		
		/*! Raises the in event 'e' that is defined in the default interface scope. */
		void raise_e();
		
		/*! Raises the in event 'f' that is defined in the default interface scope. */
		void raise_f();
		
		
		/*
		 * Functions inherited from StatemachineInterface
		 */
		virtual void init();
		
		virtual void enter();
		
		virtual void exit();
		
		virtual void runCycle();
		
		/*!
		* Checks if the state machine is active (until 2.4.1 this method was used for states).
		* A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		*/
		virtual sc_boolean isActive() const;
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		virtual sc_boolean isFinal() const;
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(SyncForkStates state) const;
	
	private:
	
	
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_integer maxOrthogonalStates = 2;
		
		
		SyncForkStates stateConfVector[maxOrthogonalStates];
		
		sc_ushort stateConfVectorPosition;
		
		DefaultSCI iface;
		
		// prototypes of all internal functions
		
		sc_boolean check_main_region_A_tr0_tr0();
		sc_boolean check_main_region_A_tr1_tr1();
		sc_boolean check_main_region_B_tr0_tr0();
		sc_boolean check_main_region_B_r1_C1_tr0_tr0();
		sc_boolean check_main_region_B_r2_D1_tr0_tr0();
		void effect_main_region_A_tr0();
		void effect_main_region_A_tr1();
		void effect_main_region_B_tr0();
		void effect_main_region_B_r1_C1_tr0();
		void effect_main_region_B_r2_D1_tr0();
		void enseq_main_region_A_default();
		void enseq_main_region_B_default();
		void enseq_main_region_B_r1_C1_default();
		void enseq_main_region_B_r1_C2_default();
		void enseq_main_region_B_r2_D1_default();
		void enseq_main_region_B_r2_D2_default();
		void enseq_main_region_default();
		void enseq_main_region_B_r1_default();
		void enseq_main_region_B_r2_default();
		void exseq_main_region_A();
		void exseq_main_region_B();
		void exseq_main_region_B_r1_C1();
		void exseq_main_region_B_r1_C2();
		void exseq_main_region_B_r2_D1();
		void exseq_main_region_B_r2_D2();
		void exseq_main_region();
		void exseq_main_region_B_r1();
		void exseq_main_region_B_r2();
		void react_main_region_A();
		void react_main_region_B_r1_C1();
		void react_main_region_B_r1_C2();
		void react_main_region_B_r2_D1();
		void react_main_region_B_r2_D2();
		void react_main_region__entry_Default();
		void react_main_region_B_r1__entry_Default();
		void react_main_region_B_r2__entry_Default();
		void react_main_region__sync0();
		void clearInEvents();
		void clearOutEvents();
		
};
#endif /* SYNCFORK_H_ */
