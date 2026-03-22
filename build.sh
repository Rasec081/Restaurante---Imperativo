#!/bin/bash

BUILD_DIR="build"
EXEC="Imperativo"  # sin .exe

# Crear carpeta build si no existe
if [ ! -d "$BUILD_DIR" ]; then
  mkdir $BUILD_DIR
fi

cd $BUILD_DIR

echo "Configurando con CMake..."
cmake ..

if [ $? -ne 0 ]; then
  echo "Error en configuracion"
  exit 1
fi

echo "Compilando..."
cmake --build .

if [ $? -ne 0 ]; then
  echo "Error en compilacion"
  exit 1
fi

if [ -f "$EXEC" ]; then
  echo "Ejecutando..."
  ./$EXEC
else
  echo "No se encontro el ejecutable: $EXEC"
fi