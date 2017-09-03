/*-------------- Video Streaming (VS) Interface Descriptor ----------------*/

/* Standard VS Interface Descriptor  = interface 1 */
// alternate setting 0 = Zero Bandwidth
.uvc_vs_if_alt0_desc = {
  .bLength = USB_DT_INTERFACE_SIZE,                // 9
  .bDescriptorType = USB_DESC_TYPE_INTERFACE,      // 4
  .bInterfaceNumber = USB_UVC_VSIF_NUM,            // 1 index of this interface
  .bAlternateSetting = 0x00,                       // 0 index of this setting
  .bNumEndpoints = 0x00,                           // 0 no EP used
  .bInterfaceClass = UVC_CC_VIDEO,                 // 14 Video
  .bInterfaceSubClass = UVC_SC_VIDEOSTREAMING,     // 2 Video Streaming
  .bInterfaceProtocol = UVC_PC_PROTOCOL_UNDEFINED, // 0 (protocol undefined)
  .iInterface = 0x00,                              // 0 no description available
},

/* Class-specific VS Header Descriptor (Input) */
.uvc_vs_input_header_desc = {
  .bLength =
    SIZEOF_M(struct usbd_uvc_cfg, uvc_vs_input_header_desc),
  .bDescriptorType = UVC_CS_INTERFACE,       // 36 (INTERFACE)
  .bDescriptorSubType = UVC_VS_INPUT_HEADER, // 1 (INPUT_HEADER)
  .bNumFormats = VS_NUM_FORMATS,       // 4 four format descriptors follow
  .wTotalLength =
    SIZEOF_M(struct usbd_uvc_cfg, uvc_vs_input_header_desc) + 
    SIZEOF_M(struct usbd_uvc_cfg, uvc_vs_frames_formats),
  .bEndpointAddress = UVC_IN_EP,             // 0x83 EP 3 IN
  .bmInfo = 0x00,                            // 0 no dynamic format change supported
  .bTerminalLink = VC_OUTPUT_TERMINAL_ID,    // 2 supplies terminal ID 2 (Output terminal)
  .bStillCaptureMethod = 0x01,               // 1 Host captures from video stream
  .bTriggerSupport = 0x00,                   // 0 HW trigger supported for still image capture
  .bTriggerUsage = 0x00,                     // 0 HW trigger initiate a still image capture
  .bControlSize = 0x01,                      // 1 one byte bmaControls field size
  .bmaControls = {
    { 0x00 },                                // bmaControls(0)           0 no VS specific controls
    { 0x00 },                                // bmaControls(1)           0 no VS specific controls
    { 0x00 },                                // bmaControls(2)           0 no VS specific controls
    { 0x00 },                                // bmaControls(3)           0 no VS specific controls
    { 0x00 },                                // bmaControls(4)           0 no VS specific controls
    { 0x00 },                                // bmaControls(4)           0 no VS specific controls
    { 0x00 },                                // bmaControls(4)           0 no VS specific controls
  },
},

.uvc_vs_frames_formats = {
  {
    .uvc_vs_format = UVC_FORMAT_UNCOMPRESSED_DESCRIPTOR(YUYV, 1),
    .uvc_vs_frame  = UVC_FRAME_FORMAT(1, YUYV, 80, 60),
    .uvc_vs_color  = UVC_COLOR_MATCHING_DESCRIPTOR(),
  },
  {
    .uvc_vs_format = UVC_FORMAT_UNCOMPRESSED_DESCRIPTOR(Y16, 1),
    .uvc_vs_frame  = UVC_FRAME_FORMAT(1, Y16, 80, 60),
    .uvc_vs_color  = UVC_COLOR_MATCHING_DESCRIPTOR(),
  },
  {
    .uvc_vs_format = UVC_FORMAT_UNCOMPRESSED_DESCRIPTOR(NV12, 1),
    .uvc_vs_frame  = UVC_FRAME_FORMAT(1, NV12, 80, 60),
    .uvc_vs_color  = UVC_COLOR_MATCHING_DESCRIPTOR(),
  },
  {
    .uvc_vs_format = UVC_FORMAT_UNCOMPRESSED_DESCRIPTOR(YU12, 1),
    .uvc_vs_frame  = UVC_FRAME_FORMAT(1, YU12, 80, 60),
    .uvc_vs_color  = UVC_COLOR_MATCHING_DESCRIPTOR(),
  },
  {
    .uvc_vs_format = UVC_FORMAT_UNCOMPRESSED_DESCRIPTOR(GREY, 1),
    .uvc_vs_frame  = UVC_FRAME_FORMAT(1, GREY, 80, 60),
    .uvc_vs_color  = UVC_COLOR_MATCHING_DESCRIPTOR(),
  },
#ifndef Y16
  {
    .uvc_vs_format = UVC_FORMAT_UNCOMPRESSED_DESCRIPTOR(RGB565, 1),
    .uvc_vs_frame  = UVC_FRAME_FORMAT(1, RGB565, 80, 60),
    .uvc_vs_color  = UVC_COLOR_MATCHING_DESCRIPTOR(),
  },
  {
    .uvc_vs_format = UVC_FORMAT_UNCOMPRESSED_DESCRIPTOR(BGR3, 1),
    .uvc_vs_frame  = UVC_FRAME_FORMAT(1, BGR3, 80, 60),
    .uvc_vs_color  = UVC_COLOR_MATCHING_DESCRIPTOR(),
  },
#endif
},