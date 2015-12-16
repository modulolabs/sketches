#include "Wire.h"
#include "Modulo.h"

TemperatureProbeModulo tempProbe;
DisplayModulo display;

// When the temperature changes, clear and redraw the display
void onTemperatureChange(TemperatureProbeModulo &t) {
    // Clear the dislay first
    display.clear();

    // Print the temperature in degrees C
    display.println(tempProbe.getTemperatureC());

    // Print the temperature in degrees F
    display.println(tempProbe.getTemperatureF());

    // Refresh the display with the new temperature
    display.refresh();
}

void setup() {
    // Need to call Modulo.setup() before drawing the display for the first time
    Modulo.setup();

    // Register our function to be called when the temperature changes
    tempProbe.setTemperatureChangeCallback(onTemperatureChange);

    // Call the temperature change callback once here to display the temperature
    // when the program starts up
    onTemperatureChange(tempProbe);
}

void loop() {
    // Handle events on each iteration of the event loop
    Modulo.loop();
}
