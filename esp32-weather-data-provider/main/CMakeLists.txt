# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRC_DIRS
    	"Src"
    	"Src/hardware"
    	"Src/service"
    INCLUDE_DIRS
    	"Inc"
    	"Inc/hardware"
    	"Inc/service"
    PRIV_INCLUDE_DIRS   # optional, add here private include directories
    REQUIRES            # optional, list the public requirements (component names)
    PRIV_REQUIRES       # optional, list the private requirements
)
