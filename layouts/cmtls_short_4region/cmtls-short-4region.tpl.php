<?php
/**
 * @file
 * Display Suite example layout template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 *
 * Regions:
 *
 * - $left: Rendered content for the "Left" region.
 * - $left_classes: String of classes that can be used to style the "Left" region.
 *
 * - $right: Rendered content for the "Right" region.
 * - $right_classes: String of classes that can be used to style the "Right" region.
 */
?>
<div class="<?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <!-- regions -->

  <?php if ($left_column): ?>
    <div class="ds-left<?php print $left_column_classes; ?>">
      <?php print $left_column; ?>
    </div>
  <?php endif; ?>

  <?php if ($right_column): ?>
    <div class="ds-right<?php print $right_column_classes; ?>">
      <?php print $right_column; ?>
    </div>
  <?php endif; ?>

  <?php if ($middle): ?>
    <div class="ds-content<?php print $middle_classes; ?>">
      <?php print $middle; ?>
    </div>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="ds-footer<?php print $footer_classes; ?>">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <!-- /regions -->

</div>
