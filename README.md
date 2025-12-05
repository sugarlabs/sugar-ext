# Sugar-Ext

The sugar4 library contains a set of widgets to build HIG compliant applications and interfaces to interact with system services like presence and the datastore.

## Dependencies

Before building, ensure you have the required dependencies installed:

### Ubuntu/Debian
```bash
sudo apt-get install meson ninja-build libgtk-4-dev libglib2.0-dev
```

### Fedora/RHEL
```bash
sudo dnf install meson ninja-build gtk4-devel glib2-devel
```

### Arch Linux
```bash
sudo pacman -S meson ninja gtk4 glib2
```

### macOS
```bash
brew install meson ninja gtk4 glib
```

### Required Versions
- GTK4 >= 4.0
- GLib >= 2.70
- Meson >= 0.56
- Ninja

## Building

This project uses Meson build system:

```bash
meson setup builddir
meson compile -C builddir
```

## Testing

Run the test suite:

```bash
meson test -C builddir
```

Tests include:

- `main_functionality`: Comprehensive test of all features
- `utilities`: Utility functions testing
- `sugar_grid`: Sugar Grid spatial layout system testing
- `sugar_event_controller`: Tests for event handling and custom event controller logic
- `sugar_file_attributes`: Tests for file attribute management and metadata handling
- `sugar_long_press_controller`: Handling the delayed controlling and senses.

## Installation

```bash
meson install -C builddir
```

## Examples

After building, you can run the example programs:

```bash
# Grid layout example
./builddir/examples/sugar_grid_example

# Event controller example
./builddir/examples/sugar_event_controller_example

# File attributes example
./builddir/examples/sugar_file_attributes_example

# Long press controller example
./builddir/examples/sugar_long_press_controller_example
```

> [!NOTE]
> Examples require a display server (X11 or Wayland). If running in a headless environment, use `xvfb-run`:
> ```bash
> xvfb-run ./builddir/examples/sugar_grid_example
> ```

## Troubleshooting

### Meson not found
If you get `meson: command not found`, install Meson using your package manager or pip:
```bash
pip install --user meson ninja
```

### GTK4 version incompatibility
Ensure you have GTK4 >= 4.0 installed:
```bash
pkg-config --modversion gtk4
```

### Display server issues
If examples fail with display errors:
- Ensure `DISPLAY` environment variable is set
- Use `xvfb-run` for headless environments
- Check that your system supports GTK4 (Wayland or X11)

### Build directory conflicts
If you encounter build errors, try cleaning and rebuilding:
```bash
rm -rf builddir
meson setup builddir
meson compile -C builddir
```

### Missing dependencies
If compilation fails with missing headers:
- Verify all dependencies are installed (see Dependencies section)
- Check that pkg-config can find the libraries:
  ```bash
  pkg-config --cflags --libs gtk4 glib-2.0
  ```
