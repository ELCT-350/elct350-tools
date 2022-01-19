# ELCT 350 Tools
Various tools for ELCT 350 assignments and projects

## Plotter Example

```cpp
#include <cmath>
#include "plotter.h"

int main()
{	
    Plotter plotter("TrigTest");

    plotter.SetLabels("sin(t)", "cos(t)", "sin(t)*(cos(t)");
    plotter.SetSize(1000, 600);

    for (double t = 0.0; t < 10.0; t += 0.01)
    {
        plotter.AddRow(t, sin(t), cos(t), sin(t)*cos(t));
    }
	
    plotter.Plot();
    return 0;
}
```

Running the above code should produce the html file *TrigTest.html* in the build directory.

Opening the html file in your browser should render the following plot:

![Image](img/trigtest.png?raw=true)
