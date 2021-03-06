/**
* Copyright (c) 2017 committers of YAKINDU and others.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*     committers of YAKINDU - initial API and implementation
*/
#include <string>
#include "gtest/gtest.h"
#include "SimpleHierachy.h"
#include "sc_types.h"
SimpleHierachy* statechart;

class StatemachineTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new SimpleHierachy();
		statechart->init();
	}
	virtual void TearDown() {
		delete statechart;
	}
};


TEST_F(StatemachineTest, simpleHierachyTest) {
	
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(SimpleHierachy::main_region_A));
	
	statechart->raise_event1();
	
	statechart->raise_event1();
	
	statechart->raise_event1();
	
	statechart->runCycle();
	
	EXPECT_TRUE(statechart->isStateActive(SimpleHierachy::main_region_B));
	
	EXPECT_TRUE(statechart->isStateActive(SimpleHierachy::main_region_B_subregion1_B1));
	
}
