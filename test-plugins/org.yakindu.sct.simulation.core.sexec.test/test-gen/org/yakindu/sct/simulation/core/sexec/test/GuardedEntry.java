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
package org.yakindu.sct.simulation.core.sexec.test;
import org.eclipse.xtext.junit4.InjectWith;
import org.eclipse.xtext.junit4.XtextRunner;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.yakindu.sct.model.sexec.ExecutionFlow;
import org.yakindu.sct.model.sexec.interpreter.test.util.AbstractExecutionFlowTest;
import org.yakindu.sct.model.sexec.interpreter.test.util.SExecInjectionProvider;
import org.yakindu.sct.test.models.SCTUnitTestModels;
import com.google.inject.Inject;
import static org.junit.Assert.assertTrue;
/**
 * Unit TestCase for GuardedEntry
 */
@SuppressWarnings("all")
@RunWith(XtextRunner.class)
@InjectWith(SExecInjectionProvider.class)
public class GuardedEntry extends AbstractExecutionFlowTest {
	@Before
	public void setup() throws Exception{
		ExecutionFlow flow = models.loadExecutionFlowFromResource("GuardedEntry.sct");
		initInterpreter(flow);
	}
	@Test
	public void entryNotTakenOnStatechartEnter() throws Exception {
		assertTrue(getBoolean("guard") == false);
		interpreter.enter();
		assertTrue(isStateActive("A"));
		assertTrue(getBoolean("done") == false);
	}
	@Test
	public void entryTakenOnStatechartEnter() throws Exception {
		setBoolean("guard", true);
		interpreter.enter();
		assertTrue(isStateActive("A"));
		assertTrue(getBoolean("done") == true);
	}
	@Test
	public void entryTakenInTransition() throws Exception {
		initEntryInTransition(true,false);
		assertTrue(getBoolean("done"));
	}
	@Test
	public void entryNotTakenInTransition() throws Exception {
		initEntryInTransition(false,false);
		assertTrue(!getBoolean("done"));
	}
	public void initEntryInTransition(boolean guardVar, boolean doneVar) throws Exception {
		interpreter.enter();
		assertTrue(isStateActive("A"));
		raiseEvent("e");
		interpreter.runCycle();
		assertTrue(isStateActive("B"));
		setBoolean("guard", guardVar);
		setBoolean("done", doneVar);
		raiseEvent("e");
		interpreter.runCycle();
		assertTrue(isStateActive("A"));
	}
}
