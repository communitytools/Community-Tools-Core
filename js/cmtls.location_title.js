(function ($) {
  Drupal.behaviors.cmtls_location_title = {
    attach: function (context, settings) {
      $('#edit-title').keyup(function () {
        $('#edit-field-cmtls-location-und-0-name').val($(this).val());
      });
      $('#edit-field-cmtls-location-und-0-name').keyup(function () {
        $('#edit-title').val($(this).val());
      });
    }
  };  
}(jQuery));