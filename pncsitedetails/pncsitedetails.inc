<?php
/**
 * @file
 * An example of how to use the new #states Form API element, allowing
 * dynamic form behavior with very simple setup.
 */

/**
 * 
 * @param array $form
 * @param array $form_state
 * @return array
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
    '#attributes' => array(
       'placeholder' => t('https://twitter.com/my-twitter-name-is-needed'),
     ),
  );
  $form['social']['facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook'),
    '#default_value' => variable_get('pnc_facebook'),
    '#attributes' => array(
       'placeholder' => t('https://facebook.com/my-facebook-name-is-needed'),
    ),
  );
  $form['social']['linkedin'] = array(
    '#type' => 'textfield',
    '#title' => t('Linkedin'),
    '#default_value' =>  variable_get('pnc_linkedin'),
    '#attributes' => array(
       'placeholder' => t('https://linkedin.com/my-linkedin-name-is-needed'),
    ),
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
  
  $form['business_hours']['other_trading_hours'] = array(
    '#type' => 'textfield',
    '#title' => t('Other trading hours'),
    '#default_value' => variable_get('pnc_trading_hours'),
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
  drupal_set_message(t('Your website details have been updated'));

}
/**
 * 
 * @param array $form_state
 */

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
   variable_set('pnc_trading_hours', $form_state['values']['other_trading_hours'] );
   variable_set('pnc_address', $form_state['values']['address'] );
   variable_set('pnc_postal_address', $form_state['values']['postal_address'] );
   variable_set('pnc_phone', $form_state['values']['phone'] );
   variable_set('pnc_business_fax', $form_state['values']['business_fax']);
   variable_set('pnc_business_email', $form_state['values']['busines_email']);
   variable_set('pnc_business_abn_acn', $form_state['values']['business_abn_acn']);
}