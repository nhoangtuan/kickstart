<?php

/**
 * @file
 * Rules integration for the Commerce add to cart confirmation module.
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_add_to_cart_confirmation_rules_action_info() {
  return array(
    'commerce_add_to_cart_confirmation_message' => array(
      'label' => t('Add to Cart message'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line item'),
        ),
      ),
      'group' => t('Commerce (contrib)'),
      'callbacks' => array(
        'execute' => 'commerce_add_to_cart_confirmation_rules_add_to_cart_message',
      ),
    ),
  );
}
//hook_rules_action_info();
//function hook_rules_action_info() {
//  return array(
//    'mail_user' => array(
//      'label' => t('Send a mail to a user'),
//      'parameter' => array(
//        'user' => array('type' => 'user', 'label' => t('Recipient')),
//      ),
//      'group' => t('System'),
//      'base' => 'rules_action_mail_user',
//      'callbacks' => array(
//        'validate' => 'rules_action_custom_validation',
//        'help' => 'rules_mail_help',
//      ),
//    ),
//  );
//}
/**
 * Rules action: displays a custom Add to Cart message.
 */
function commerce_add_to_cart_confirmation_rules_add_to_cart_message($line_item, $continue) {
 
 $message = '<div class="added-product-title clearfix">' . t('Thêm thành công') . '</div>';
  $message .= '<div class="button-wrapper">';
  $message .= '<div class="button checkout">' . l(t('Go to checkout'), 'cart') . '</div>';
  $message .= '<div class="button continue"><span class="commerce-add-to-cart-confirmation-close">' . t('Continue shopping') . '</span></div>';
  $message .= '</div>';
  $message .= views_embed_view('confirm_message_product_display', 'default', $line_item->line_item_id);

    
  $close = t('Close');

  drupal_set_message('<div class="message-inner">' . $message . '<a class="commerce-add-to-cart-confirmation-close" href="#"><span class="element-invisible">' . $close . '</span></a></div>', 'commerce-add-to-cart-confirmation');
}
