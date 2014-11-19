<div class="lightboxOverlay"`>
</div>
 <div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> lightboxContainer"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($subject): ?>
     <h2<?php print $title_attributes; ?>>Request New Account</h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>
  <div class="content"<?php print $content_attributes; ?>>
    <?php //print drupal_render_children($content); ?>
     <form class="user-info-from-cookie" enctype="multipart/form-data" action="/" method="post" id="user-register-form" accept-charset="UTF-8">
       <?php  print drupal_render($content['account']['name']); ?>
       <?php  //print drupal_render($content['field_last_name']); ?>
       <?php  print drupal_render($content['account']['mail']); ?>
       <?php  //print drupal_render($content['field_contact_phone']); ?>
       <?php  print drupal_render($content['form_build_id']); ?>
       <?php  print drupal_render($content['form_id']); ?>
       <?php  print drupal_render($content['actions']); ?>
     </form>
   </div>
   <div class="clear-div">
 </div>
