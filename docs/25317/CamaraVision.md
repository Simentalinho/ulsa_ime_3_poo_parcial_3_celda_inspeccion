# Documentación de la clase CamaraVision

**Documentación elaborada por:** Yair Alberto Flores Peña  
**Matrícula:** 25317  
**Clase asignada:** CamaraVision

## 1. Propósito

La cámara de visión `V-01` revisa cuántos defectos visibles tiene cada pieza. La celda usa esta cámara durante el turno para decidir si la pieza cumple con la inspección visual.

## 2. Decisiones de diseño

`CamaraVision` hereda de `Dispositivo`. El constructor recibe el ID y se lo pasa a la clase base, así que la cámara no necesita atributos propios. Tampoco requiere calibración.

Sobrescribe `descripcion()`, que devuelve `Camara de vision`, e `inspeccionar()`, que devuelve `true` cuando `pieza.defectos() == 0`. Los dos métodos son `const` porque no cambian el estado de la cámara.

La celda recibe la cámara mediante `agregarDispositivo()` y la usa como un `Dispositivo`. Por eso puede ejecutar la inspección de la cámara sin tener código especial para ella.

## 3. Pruebas

En una prueba aislada se llamó a la cámara mediante una referencia a `Dispositivo`. Una pieza con cero defectos fue aceptada y otra con un defecto fue rechazada.

## 4. Bitácora

La primera versión revisada del repositorio tenía archivos de integración incompletos. Se probó la cámara por separado para comprobar su regla de inspección mientras se localizaba la versión completa del equipo.