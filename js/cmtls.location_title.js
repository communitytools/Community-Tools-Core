(function ($) {
  Drupal.behaviors.cmtls_location_title = {
    attach: function (context, settings) {
      $('#edit-title').keyup(function () {
        $('#edit-field-cmtls-address-und-0-name-line').val($(this).val());
      });
      $('#edit-field-cmtls-address-und-0-name-line').keyup(function () {
        $('#edit-title').val($(this).val());
      });
    }
  };
}(jQuery));