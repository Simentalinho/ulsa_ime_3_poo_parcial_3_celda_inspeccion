# Documentación de la clase Bascula

**Documentación elaborada por:** Alejandro Serrato de la Rosa  
**Matrícula:** 25206  
**Clase asignada:** Bascula

## 1. Propósito

La báscula `B-01` se encarga de medir el peso de cada pieza durante el proceso de inspección. La celda utiliza este dispositivo para verificar que el peso de las piezas se encuentre dentro del rango permitido, de 10.0 a 15.0 kg, y determinar si cumplen con este criterio de calidad.

## 2. Decisiones de diseño

`Bascula` hereda de `Dispositivo` e implementa la interfaz `Calibrable`. El constructor recibe el identificador del dispositivo y lo transmite a la clase base. Además, cuenta con el atributo privado `desfase_`, que permite representar la diferencia entre el peso real y el peso medido.

El desfase inicial de la báscula es de +0.4 kg. El método `inspeccionar()` obtiene el peso de la pieza mediante `pieza.peso()`, suma el desfase y comprueba que el resultado esté entre 10.0 y 15.0 kg.

El método `calibrar()` establece el desfase en 0.0 para eliminar la diferencia de medición. Por otra parte, `descripcion()` devuelve el nombre del dispositivo: `Bascula`.

Los métodos `inspeccionar()` y `descripcion()` son constantes (`const`) porque no modifican el estado del dispositivo durante su ejecución.

La celda utiliza la báscula mediante la clase base `Dispositivo`, permitiendo integrar su funcionamiento con los demás dispositivos de inspección.

## 3. Pruebas

Se verificó el funcionamiento de la báscula durante la ejecución general de la celda de inspección.

Se comprobó que el dispositivo realizara correctamente su calibración y aplicara el rango de aceptación establecido. Durante el procesamiento de las 12 piezas del turno, la báscula registró 2 rechazos, correspondientes a las piezas que no cumplieron con el criterio de peso.

También se comprobó que el funcionamiento de la báscula no afectara los resultados de los demás dispositivos.

La ejecución final del proyecto obtuvo 12 piezas inspeccionadas, 6 aceptadas y 6 rechazadas, mostrando el mensaje `Reporte correcto`.

## 4. Bitácora

Se realizó una revisión de la declaración e implementación de la clase `Bascula`, verificando la herencia de `Dispositivo`, la implementación de `Calibrable`, el encapsulamiento del atributo `desfase_` y la correspondencia entre los archivos `Bascula.h` y `Bascula.cpp`.

Se revisaron las condiciones de medición, el desfase inicial de +0.4 kg y el procedimiento de calibración a cero. No se encontraron errores que requirieran modificaciones en estos archivos.

Finalmente, se participó en la revisión y verificación de integración del proyecto, comprobando que la compilación y ejecución general conservaran los resultados esperados.