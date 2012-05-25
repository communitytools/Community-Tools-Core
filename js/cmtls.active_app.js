(function ($) {
  Drupal.behaviors.cmtls_active_app = {
    attach: function (context, settings) {
      if(Drupal.settings.cmtls && Drupal.settings.cmtls.current_app && Drupal.settings.cmtls.current_app.nid) {
        $('.cmtls-app-select-link[data-nid="' + Drupal.settings.cmtls.current_app.nid + '"]').addClass('active');
      }
    }
  };  
}(jQuery));