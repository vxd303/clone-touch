
# --- OpenCV shim: some packaged opencv2.framework headers expect opencv2/<module>/... paths.
# Create symlinks inside frameworks/opencv2.framework/Headers/opencv2 to point back to ../<module>.
OPENCV_HEADERS_DIR := $(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
OPENCV_SHIM_DIR := $(OPENCV_HEADERS_DIR)/opencv2

before-all::
	@if [ -d "$(OPENCV_HEADERS_DIR)" ]; then \
		mkdir -p "$(OPENCV_SHIM_DIR)"; \
		for d in core imgproc imgcodecs highgui video videoio features2d calib3d flann objdetect ml photo stitching dnn; do \
			if [ -d "$(OPENCV_HEADERS_DIR)/$$d" ] && [ ! -e "$(OPENCV_SHIM_DIR)/$$d" ]; then \
				ln -s "../$$d" "$(OPENCV_SHIM_DIR)/$$d"; \
			fi; \
		done; \
		for h in core.hpp imgproc.hpp imgcodecs.hpp highgui.hpp video.hpp videoio.hpp features2d.hpp calib3d.hpp flann.hpp objdetect.hpp ml.hpp photo.hpp stitching.hpp dnn.hpp opencv_modules.hpp; do \
			if [ -f "$(OPENCV_HEADERS_DIR)/$$h" ] && [ ! -e "$(OPENCV_SHIM_DIR)/$$h" ]; then \
				ln -s "../$$h" "$(OPENCV_SHIM_DIR)/$$h"; \
			fi; \
		done; \
	fi

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

# Ensure OpenCV headers are found for ObjC++ tool builds (Xcode 16+ is stricter)
zxtouchb_CCFLAGS = -std=c++11

zxtouchd_CFLAGS+= -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchd_CCFLAGS+= -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchd_LDFLAGS += -F$(THEOS_PROJECT_DIR)/frameworks
zxtouchd_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers
zxtouchd_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers

# Some opencv2.framework bundles (including the one committed in this repo)
# expose headers under "Headers" (without a Versions/ directory), and may be
zxtouchd_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchd_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers

zxtouchb_CFLAGS+= -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchb_CCFLAGS+= -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchb_LDFLAGS += -F$(THEOS_PROJECT_DIR)/frameworks
zxtouchb_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers
zxtouchb_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers

zxtouchb_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchb_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers


### OpenCV header search paths (tool targets): use ADDITIONAL_*FLAGS (THEOS) so ObjC++ .xm->.mm picks them up reliably
zxtouchd_ADDITIONAL_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchd_ADDITIONAL_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchb_ADDITIONAL_CFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers
zxtouchb_ADDITIONAL_CCFLAGS += -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Versions/A/Headers -I$(THEOS_PROJECT_DIR)/frameworks/opencv2.framework/Headers

zxtouchd_EXTRA_FRAMEWORKS = opencv2
zxtouchb_EXTRA_FRAMEWORKS = opencv2

include $(THEOS_MAKE_PATH)/tool.mk
