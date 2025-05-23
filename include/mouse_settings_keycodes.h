  #include <dt-bindings/zmk/mouse.h>
  #include <dt-bindings/zmk/mouse_settings.h>
  #include <behaviors/mouse_keys.dtsi>
  #include <behaviors/mouse_setting.dtsi>

 /*
  * Key Behaviors to adjust settings
  */

  // They key codes below can be used to adjust the TP settings at runtime
  // without needing to recompile the firmware.
  //
  // The values will be logged and saved in the config on the controller flash
  // after 60s (CONFIG_ZMK_SETTINGS_SAVE_DEBOUNCE).
  //
  // On boot the settings will be restored again.
  //
  // If you prefer a more explicit way of configuration, you can also hardcode
  // these settings in `&mouse_ps2`.
  //
  // If you set these settings in `&mouse_ps2`, you will still be able to
  // adjust the values during runtime with these key codes, but after
  // restarting the board the values in `&mouse_ps2` will be restored and not
  // the ones stored in the flash using the key codes.


  // How sensitive the trackpoint is
  #define U_MSS_TP_S_I &mms MS_TP_SENSITIVITY_INCR
  #define U_MSS_TP_S_D &mms MS_TP_SENSITIVITY_DECR


  // The maximum speed the trackpoint will accelerate to
  #define U_MSS_TP_V6_I &mms MS_TP_VALUE6_INCR
  #define U_MSS_TP_V6_D &mms MS_TP_VALUE6_DECR


  // I am not quite sure tbh... default seems fine.
  #define U_MSS_TP_NI_I &mms MS_TP_NEG_INERTIA_INCR
  #define U_MSS_TP_NI_D &mms MS_TP_NEG_INERTIA_DECR


  // How hard you have to press to activate the "Press To Select" feature that
  // lets you tap or press on the trackpoint to click.
  //
  // Not all trackpoints support it and you have to enable
  // `tp-press-to-select;` in `&mouse_ps2` first.
  #define U_MSS_TP_PT_I &mms MS_TP_PTS_THRESHOLD_INCR
  #define U_MSS_TP_PT_D &mms MS_TP_PTS_THRESHOLD_DECR


  // If you mess up the settings, you can use this key code to clear the
  // settings from flash and re-set the default values on the TP.
  //
  // Make sure to wait at least CONFIG_ZMK_SETTINGS_SAVE_DEBOUNCE seconds (60
  // by default) before restarting the board to ensure the settings are
  // written to flash storage.
  #define U_MSS_RESET   &mms MS_RESET


  // If you prefer to set the settings in `&mouse_ps2`, you can use the key
  // codes above to find the settings you like the most and then press this
  // key code to output the settings to the log.
  //
  // Then you can add those values to `&mouse_ps2`
  #define U_MSS_LOG     &mms MS_LOG