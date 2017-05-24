/**
 */
package org.yakindu.base.generator.generator;

import org.eclipse.emf.common.util.EList;

import org.yakindu.base.types.TypeSpecifier;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Method Gen</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link org.yakindu.base.generator.generator.MethodGen#getParameters <em>Parameters</em>}</li>
 *   <li>{@link org.yakindu.base.generator.generator.MethodGen#getReturnType <em>Return Type</em>}</li>
 * </ul>
 *
 * @see org.yakindu.base.generator.generator.GeneratorPackage#getMethodGen()
 * @model
 * @generated
 */
public interface MethodGen extends CodeElement, AccessRestricted {
	/**
	 * Returns the value of the '<em><b>Parameters</b></em>' reference list.
	 * The list contents are of type {@link org.yakindu.base.generator.generator.ParameterGen}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Parameters</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Parameters</em>' reference list.
	 * @see org.yakindu.base.generator.generator.GeneratorPackage#getMethodGen_Parameters()
	 * @model
	 * @generated
	 */
	EList<ParameterGen> getParameters();

	/**
	 * Returns the value of the '<em><b>Return Type</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Return Type</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Return Type</em>' reference.
	 * @see #setReturnType(TypeSpecifier)
	 * @see org.yakindu.base.generator.generator.GeneratorPackage#getMethodGen_ReturnType()
	 * @model
	 * @generated
	 */
	TypeSpecifier getReturnType();

	/**
	 * Sets the value of the '{@link org.yakindu.base.generator.generator.MethodGen#getReturnType <em>Return Type</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Return Type</em>' reference.
	 * @see #getReturnType()
	 * @generated
	 */
	void setReturnType(TypeSpecifier value);

} // MethodGen