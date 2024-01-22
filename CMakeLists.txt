#cmake_minimum_required(VERSION 3.23)
#project(MultMat_Sec3 C)

#set(CMAKE_CXX_STANDARD 14)

#set(SOURCE_FILES Errors.c Matrix.c Standard_MultMat.c Strassens_MultMat.c)

#add_executable(MultMat_Sec MultMat_Sec.c  ${SOURCE_FILES}
 #       Concurrent_Standard_MultMat.h
  #      Concurrent_Standard_MultMat.c
   #     Concurrent_Strassens_MultMat.h
    #    Concurrent_Strassens_MultMat.c
     #   MultMat_Concurrent.c
      #  MultMatConcurrent_test.c
#)
#add_executable(MultMat_Test MultMat_Test.c ${SOURCE_FILES} )
cmake_minimum_required(VERSION 3.23)
project(MultMat_Concurrent C)

set(CMAKE_C_STANDARD 11) # Usamos C11 porque es C y no C++

# Lista todos tus archivos fuente y de encabezado
set(SOURCE_FILES
        Errors.c
        Matrix.c
        Concurrent_Standard_MultMat.c
        Concurrent_Strassens_MultMat.c
)

# Define el ejecutable para tu programa principal concurrente
add_executable(MultMat_Concurrent MultMat_Concurrent.c ${SOURCE_FILES})

# Define el ejecutable para tus pruebas concurrentes
add_executable(MultMatConcurrent_Test MultMatConcurrent_test.c ${SOURCE_FILES})

# Configura la ruta de los include para que el compilador sepa dónde buscar los archivos .h
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

