<?php

/**
 * @file
 * An example of how to use the new #states Form API element, allowing
 * dynamic form behavior with very simple setup.
 */

/**
 * States demo form.
 *
 * This form shows off the #states system by dynamically showing parts of the
 * form based on the state of other parts.
 *
 * @ingroup form_example
 *
 * The basic idea is that you add a #states property to the element which is
 * to be changed based on some action elsewhere on the form. The #states
 * property lists a change which is to be made, and under what conditions
 * that change should be made.
 *
 * For example, in the 'tests_taken' form element below we have:
 * @code
 * '#states' => array(
 *   'visible' => array(
 *     ':input[name="student_type"]' => array('value' => 'high_school'),
 *   ),
 * ),
 * @endcode
 * Meaning that the element is to be made visible when the condition is met.
 * The condition is a combination of a jQuery selector (which selects the
 * element we want to test) and a condition for that element. In this case,
 * the condition is whether the return value of the 'student_type' element is
 * 'high_school'. If it is, this element will be visible.
 *
 * So the syntax is:
 * @code
 * '#states' => array(
 *   'action_to_take_on_this_form_element' => array(
 *     'jquery_selector_for_another_element' => array(
 *       'condition_type' => value,
 *     ),
 *   ),
 * ),
 * @endcode
 *
 * If you need an action to take place only when two different conditions are
 * true, then you add both of those conditions to the action. See the
 * 'country_writein' element below for an example.
 *
 * Note that the easiest way to select a textfield, checkbox, or select is with
 * the
 * @link http://api.jquery.com/input-selector/ ':input' jquery shortcut @endlink,
 * which selects any any of those.
 *
 * There are examples below of changing or hiding an element when a checkbox
 * is checked, when a textarea is filled, when a select has a given value.
 *
 * See drupal_process_states() for full documentation.
 *
 * @see forms_api_reference.html
 */
function form_pncsitedetails($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Web site information'),
  );
  $form['social'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social Media'),
  );
  $form['social']['twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter'),
    '#default_value' => variable_get('pnc_twitter'),
    '#suffix' => '<small>https://twitter.com/my-twitter-name-is-needed</small>',
  );
  $form['social']['facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook'),
    '#default_value' => variable_get('pnc_facebook'),
    '#suffix' => '<small>https://facebook.com/my-facebook-name-is-needed</small>',
  );
  $form['social']['linkedin'] = array(
    '#type' => 'textfield',
    '#title' => t('Linkedin'),
    '#default_value' =>  variable_get('pnc_linkedin'),
    '#suffix' => '<small>https://linkedin.com/my-linkedin-name-is-needed</small>',
  );
  $form['business_hours'] = array(
    '#type' => 'fieldset',
    '#title' => t('Business Hours'),
  );
  $form['business_hours']['monday'] = array(
    '#type' => 'textfield',
    '#title' => t('Monday'),
    '#default_value' => variable_get('pnc_monday'),
  );
  $form['business_hours']['tuesday'] = array(
    '#type' => 'textfield',
    '#title' => t('Tuesday'),
    '#default_value' => variable_get('pnc_tuesday'),
  );
  $form['business_hours']['wednesday'] = array(
    '#type' => 'textfield',
    '#title' => t('Wednesday'),
    '#default_value' => variable_get('pnc_wednesday'),
  );
  $form['business_hours']['thursday'] = array(
    '#type' => 'textfield',
    '#title' => t('Thursday'),
    '#default_value' => variable_get('pnc_thursday'),
  );
  $form['business_hours']['friday'] = array(
    '#type' => 'textfield',
    '#title' => t('Friday'),
    '#default_value' => variable_get('pnc_friday'),
  );
   $form['business_hours']['saturday'] = array(
    '#type' => 'textfield',
    '#title' => t('Saturday'),
    '#default_value' => variable_get('pnc_saturday'),
  );
     
  $form['business_hours']['sunday'] = array(
    '#type' => 'textfield',
    '#title' => t('Sunday'),
    '#default_value' => variable_get('pnc_sunday'),
  );
  
  $form['business_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Business Details'),
  );
  $form['business_details']['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Business Address'),
    '#default_value' => variable_get('pnc_address'),
  );
  $form['business_details']['postal_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal Address'),
    '#default_value' => variable_get('pnc_postal_address'),
  );
  $form['business_details']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Business Phone'),
    '#default_value' => variable_get('pnc_phone'),
  );
  
  $form['business_details']['business_fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Business Fax'),
    '#default_value' => variable_get('pnc_business_fax'),
  );
  
  $form['business_details']['busines_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Business Email'),
    '#default_value' => variable_get('pnc_business_email'),
  );
  
  $form['business_details']['business_abn_acn'] = array(
    '#type' => 'textfield',
    '#title' => t('Business ABN/ACN'),
    '#default_value' => variable_get('pnc_business_abn_acn'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );


  
 
  return $form;
}

/**
 * Submit handler for form_example_states_form().
 */
function form_pncsitedetails_submit($form, &$form_state) {
  _pnc_set_site_details($form_state);
  
  
  $x = variable_get('pnc_twitter');
  $x .= variable_get('pnc_twitter');
  $x .=  variable_get('pnc_facebook');
  $x .=  variable_get('pnc_linkedin');
  $x .=  variable_get('pnc_monday');
  $x .=  variable_get('pnc_tuesday');
  $x .=  variable_get('pnc_wednesday');
  $x .=  variable_get('pnc_thursday');
  $x .=  variable_get('pnc_friday');
  $x .=  variable_get('pnc_saturday');
  $x .=  variable_get('pnc_sunday');
  $x .=  variable_get('pnc_address');
  $x .=  variable_get('pnc_postal_address');
  $x .=  variable_get('pnc_phone');
  $x .=  variable_get('pnc_business_fax');
  $x .=  variable_get('pnc_business_email');
  $x .=  variable_get('pnc_business_abn_acn');
   
  //drupal_set_message(t('Updates site details @values', array('@values' => $x)));
  //drupal_set_message(t('Submitting values: @values', array('@values' => var_export($form_state['values'], TRUE))));

}

function _pnc_set_site_details($form_state) {	
   variable_set('pnc_twitter', $form_state['values']['twitter']);
   variable_set('pnc_facebook', $form_state['values']['facebook'] );
   variable_set('pnc_linkedin', $form_state['values']['linkedin'] );
   variable_set('pnc_monday', $form_state['values']['monday'] );
   variable_set('pnc_tuesday', $form_state['values']['tuesday'] );
   variable_set('pnc_wednesday', $form_state['values']['wednesday']);
   variable_set('pnc_thursday', $form_state['values']['thursday'] );
   variable_set('pnc_friday', $form_state['values']['friday'] );
   variable_set('pnc_saturday', $form_state['values']['saturday'] );
   variable_set('pnc_sunday', $form_state['values']['sunday'] );
   variable_set('pnc_address', $form_state['values']['address'] );
   variable_set('pnc_postal_address', $form_state['values']['postal_address'] );
   variable_set('pnc_phone', $form_state['values']['phone'] );
   variable_set('pnc_business_fax', $form_state['values']['business_fax']);
   variable_set('pnc_business_email', $form_state['values']['busines_email']);
   variable_set('pnc_business_abn_acn', $form_state['values']['business_abn_acn']);
}