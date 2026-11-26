# Celda Robótica de Inspección de Calidad

Proyecto del Parcial 3 de Programación Orientada a Objetos.

La guía completa del proyecto está en [PROYECTO.md](PROYECTO.md). Léanla antes de empezar.

## 1. Equipo

| Integrante | Matrícula | Nombre | Usuario de GitHub | Clase |
| --- | --- | --- | --- | --- |
| 1 |25173 |Cesar Leonardo Garrido |clgarridog | |
| 2 | 25127 |Jesus Humberto Gonzalez Bonilla | Hormigrifa| ReporteTurno |
| 3 | 25104  | Diego Emilio Simental Perez| simentalinho |SensorTemperatura |
| 4 | 25317 | Yair Alberto Flores Peña | yairflores09| Camara Vision|
| 5 | | | | |
| 6 (solo equipo de seis) | | | | |

## 2. Cómo compilar y ejecutar

Escriban el comando exacto que usa el equipo para compilar y el comando para ejecutar.

g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o celda
.\celda.exe

## 3. Contrato de `Dispositivo` y `Calibrable`

**¿Qué errores dio el compilador al compilar el repositorio base y qué significaba cada uno?**

A- Error en dynamic_cast: la clase Dispositivo no era polimórfica porque no tenía métodos virtuales.
- Métodos no declarados: las interfaces estaban incompletas y no tenían todos los métodos necesarios para realizar la calibración y la inspección.
- Contratos incompletos: la celda no podía utilizar correctamente las capacidades de los dispositivos hasta completar sus clases base.
Estos problemas se solucionan declarando los métodos correspondientes y utilizando funciones virtuales para implementar el polimorfismo.    

**¿Qué métodos agregaron a `Dispositivo`? ¿Cuáles son virtuales puros, cuáles son `const` y por qué el destructor es virtual?**

virtual bool inspeccionar(const Pieza& pieza) const = 0; — evalúa si la pieza cumple la regla del dispositivo (const porque inspeccionar no modifica el estado del dispositivo ni de la pieza).

virtual std::string descripcion() const = 0; — devuelve el nombre/descripción del dispositivo para la salida del turno (const porque solo consulta información).
Constructor / ID: manejo del identificador del dispositivo (por ejemplo, id() const o constructor protegido/público según el diseño acordado).

Destructor virtual: virtual ~Dispositivo() = default; — es fundamental que sea virtual para que, si en algún momento se destruye un objeto derivado a través de un puntero Dispositivo*, se invoque primero el destructor de la clase derivada y luego el de Dispositivo, evitando comportamiento indefinido o fugas de recursos.

**¿Qué agregaron a `Calibrable` y por qué no tiene atributos?**

Se agregó el método virtual puro virtual bool calibrar() = 0; (y destructor virtual virtual ~Calibrable() = default;). Calibrable funciona como una interfaz que representa únicamente una capacidad (poder calibrarse), no un estado común compartido por todos los objetos calibrables. Cada clase concreta (Bascula, CalibradorLaser, o futuras clases calibrables) decide cómo almacena y reinicia su propio desfase (desfase_ = 0.0), manteniendo la interfaz limpia y desacoplada.

## 4. Cálculo a mano del reporte

Turno de 12 piezas, con la celda ya calibrada. Escriban `ACEPTA` o `RECHAZA` por dispositivo. La columna D-01 solo la llena el equipo de seis.

Pieza	B-01	L-01	V-01	T-01	D-01	Resultado
P-01	ACEPTA	ACEPTA	ACEPTA	ACEPTA	ACEPTA	ACEPTADA
P-02	ACEPTA	ACEPTA	ACEPTA	ACEPTA	ACEPTA	ACEPTADA
P-03	RECHAZA	ACEPTA	ACEPTA	ACEPTA	ACEPTA	RECHAZADA
P-04	ACEPTA	ACEPTA	ACEPTA	ACEPTA	ACEPTA	ACEPTADA
P-05	ACEPTA	RECHAZA	ACEPTA	ACEPTA	ACEPTA	RECHAZADA
P-06	ACEPTA	ACEPTA	RECHAZA	ACEPTA	ACEPTA	RECHAZADA
P-07	ACEPTA	ACEPTA	ACEPTA	RECHAZA	ACEPTA	RECHAZADA
P-08	RECHAZA	RECHAZA	RECHAZA	ACEPTA	ACEPTA	RECHAZADA
P-09	ACEPTA	ACEPTA	ACEPTA	ACEPTA	RECHAZA	ACEPTADA (equipo de 5) / RECHAZADA (equipo de 6)
P-10	ACEPTA	ACEPTA	ACEPTA	ACEPTA	RECHAZA	ACEPTADA (equipo de 5) / RECHAZADA (equipo de 6)
P-11	ACEPTA	ACEPTA	ACEPTA	RECHAZA	ACEPTA	RECHAZADA
P-12	ACEPTA	ACEPTA	ACEPTA	ACEPTA

**Reporte esperado (inspeccionadas, aceptadas, rechazadas y rechazos por dispositivo):**

[Inserta aquí tu respuesta]

**¿Coincide con lo que imprime el programa? Si no coincidió al primer intento, ¿qué encontraron y cómo lo corrigieron?**

=== Reporte de turno ===
Inspeccionadas: 12
Aceptadas: 6
Rechazadas: 6
Rechazos por dispositivo:
B-01: 2
L-01: 2
T-01: 2
V-01: 2

## 5. Diagrama de clases

Diagrama de clases de la solución completa, hecho en draw.io. Guarden la imagen en la raíz del repositorio como `diseno_solucion.png`.

![Diagrama de clases](diseno_solucion.png)

## 6. Documentación individual

| Integrante | Documentación de su clase | Rama del reto opcional |
| --- | --- | --- |
| Yair Flores | [CamaraVision](docs/25317/CamaraVision.md) | No |
| | `docs/<matrícula>/<Clase>.md` | `<matrícula>` o "No" |
| | | |
| | | |
| | | |
| | | |
| | | |

Los resultados de los experimentos están en [docs/experimentos.md](docs/experimentos.md).

## 7. Prueba de extensibilidad

**¿Qué archivos tuvieron que crear o modificar? ¿Tuvieron que tocar `CeldaInspeccion`?**

Para la prueba usamos un archivo `.cpp` temporal con un `main` de prueba. Ahí creamos `SensorDePrueba`, con ID `PR-01`, que hereda de `Dispositivo` y sobrescribe `descripcion()` e `inspeccionar()`. Lo registramos con `agregarDispositivo()`.

La celda aceptó una pieza con cero defectos y rechazó otra con un defecto. El reporte registró dos piezas inspeccionadas, una aceptada y un rechazo para `PR-01`. Pudimos hacer la prueba sin modificar `CeldaInspeccion` ni el `main.cpp` del proyecto.

## 8. Reflexión del equipo

**¿Qué aprendieron en este proyecto?**

Aprendimos a usar clases abstractas y polimorfismo para que la celda pueda trabajar con distintos dispositivos. Cada dispositivo aplica su propia regla de inspección. Por ejemplo, la cámara acepta una pieza si tiene cero defectos visibles. También vimos cómo separar la calibración de la inspección y cómo registrar qué dispositivo rechazó cada pieza.

**¿Qué cambiarían de su proceso de trabajo como equipo?**

Desde el inicio acordaríamos en qué repositorio y rama vamos a integrar el código. Avisaríamos al equipo al subir cambios y compilaríamos el proyecto completo después de cada integración. Así podríamos detectar a tiempo si falta subir un archivo o si el reporte del turno sale distinto al esperado.