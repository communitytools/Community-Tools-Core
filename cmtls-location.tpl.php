<div class="location vcard">
  <div class="adr">
    <?php if (isset($latitude) && isset($longitude)): ?>
      <?php // Assume that 0, 0 is invalid. ?>
      <?php if ($latitude != 0 || $longitude != 0): ?>
         <span>has-geo-coords</span>
      <?php endif; ?>
    <?php endif; ?>
    <?php if (!empty($name)): ?>
      <span class="fn"><?php print $name; ?></span>
    <?php endif; ?>
    <?php if (!empty($street)): ?>
      <div class="street-address">
        <?php print $street; ?>
        <?php if (!empty($additional)): ?>
          <?php print ' ' . $additional; ?>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
