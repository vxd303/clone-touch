#export THEOS_DEVICE_IP = 192.168.101.245

include $(THEOS)/makefiles/common.mk

TOOL_NAME = zxtouchd zxtouchb
zxtouchd_ARCH = arm64e arm64
zxtouchb_ARCH = arm64e arm64

zxtouchd_FILES = main.mm SocketServer.mm SBIPC.mm Common.xm Screen.xm ScreenMatch.xm TemplateMatch.xm TextRecognization/VKOcrManager.xm TextRecognization/TextRecognizer.xm
zxtouchb_FILES = main.mm SocketServer.mm SBIPC.mm Common.xm Screen.xm ScreenMatch.xm TemplateMatch.xm TextRecognization/VKOcrManager.xm TextRecognization/TextRecognizer.xm

zxtouchd_FRAMEWORKS = CoreFoundation UIKit CoreGraphics IOSurface Photos Vision CoreImage ImageIO
zxtouchb_FRAMEWORKS = CoreFoundation UIKit CoreGraphics IOSurface Photos Vision CoreImage ImageIO

zxtouchd_PRIVATE_FRAMEWORKS = IOKit MobileCoreServices
zxtouchb_PRIVATE_FRAMEWORKS = IOKit MobileCoreServices
zxtouchd_CFLAGS = -fobjc-arc -Wno-error -Wno-module-import-in-extern-c -O2 -s -DNDEBUG
zxtouchb_CFLAGS = -fobjc-arc -Wno-error -Wno-module-import-in-extern-c -O2 -s -DNDEBUG

zxtouchd_CCFLAGS = -std=c++11
zxtouchb_CCFLAGS = -std=c++11

zxtouchd_CFLAGS += -F$(THEOS_PROJECT_DIR)/frameworks
zxtouchd_LDFLAGS += -F$(THEOS_PROJECT_DIR)/frameworks
zxtouchd_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers
zxtouchd_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers

zxtouchb_CFLAGS += -F$(THEOS_PROJECT_DIR)/frameworks
zxtouchb_LDFLAGS += -F$(THEOS_PROJECT_DIR)/frameworks
zxtouchb_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers
zxtouchb_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers

zxtouchd_EXTRA_FRAMEWORKS = opencv2
zxtouchb_EXTRA_FRAMEWORKS = opencv2

include $(THEOS_MAKE_PATH)/tool.mk
