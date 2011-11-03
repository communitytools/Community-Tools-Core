(function ($) {
  Drupal.behaviors.cmtls_location_autocomplete = {
    attach: function (context, settings) {
      $('.cmtls-location-autocomplete', context).autocomplete({
        minLength: 2,
        
        source: function (request, response) {
          var fid = $(this.element).attr('id').split('-');
          fid.pop();
          fid = fid.join('-') + '-';
          
          // @todo: cache ajax call results
          $.ajax({
            url: Drupal.settings.basePath + 'cmtls/location/ac/' + request.term,
            dataType: 'json',
            success: function (data) {
              response($.map(data, function (item) {
                return {
                  label: item.name,
                  value: item.value,
                  location: item,
                  fid: fid
                }
              }));
            }
          });
        },
        
        select: function (event, ui) {
          var item = ui.item;
          
          for(var i in item.location) {
            $('#' + item.fid + i.replace('_', '-')).val(item.location[i]);
          }
          
          if(item.location.latitude && item.location.latidude != 0.000000 && $('#gmap-auto1map-locpick_latitude0').length > 0) {
            $('#gmap-auto1map-locpick_latitude0').val(item.location.latitude).change();
          }
          
          if(item.location.longitude && item.location.longitude != 0.000000 && $('#gmap-auto1map-locpick_longitude0').length > 0) {
            $('#gmap-auto1map-locpick_longitude0').val(item.location.longitude).change();
          }
        }
      });
    }
  };  
}(jQuery));