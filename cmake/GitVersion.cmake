# git version generate

find_package(Git)

# 生成版本描述字符串类似 TAG-X-gHASH
execute_process(COMMAND ${GIT_EXECUTABLE} describe --abbrev=6 --dirty --always --tags
    WORKING_DIRECTORY ${GIT_SOURCE_DIR}
    OUTPUT_VARIABLE  GIT_REPO_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
# 获取最新 commit 日期，YYYY-MM-DD
execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --format=%cd --date=short
    WORKING_DIRECTORY ${GIT_SOURCE_DIR}
    OUTPUT_VARIABLE  GIT_REPO_DATE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
# 获取最新 commit Hash
execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --format=%H
    WORKING_DIRECTORY ${GIT_SOURCE_DIR}
    OUTPUT_VARIABLE  GIT_REPO_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(TIMESTAMP AP_RELEASE_TIMESTAMP "%y%m%d")
string(TIMESTAMP AP_BUILD_TIMESTAMP "%Y-%m-%d %H:%M:%S")

# 写入头文件宏定义的版本字符串，日期和 Hash
file(WRITE ${PROJECT_BINARY_DIR}/ConfigVersion.h
"
#undef AP_REPO_VERSION
#define AP_REPO_VERSION \"${GIT_REPO_VERSION}\"

#undef AP_REPO_DATE
#define AP_REPO_DATE \"${GIT_REPO_DATE}\"

#undef AP_REPO_HASH
#define AP_REPO_HASH \"${GIT_REPO_HASH}\"

#undef AP_VERSION
#define AP_VERSION \"${PROJECT_NAME} MCS version ${GIT_REPO_VERSION} build ${AP_RELEASE_TIMESTAMP}\"

#undef AP_BUILD_NAME
#define AP_BUILD_NAME  \"${PROJECT_NAME}\"

#undef AP_BUILD_TIMESTAMP
#define AP_BUILD_TIMESTAMP  \"${AP_BUILD_TIMESTAMP}\"
"
)
