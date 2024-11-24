# Multiple 2D House Drawing Program

This program allows you to draw and manipulate 2D house instances using keyboard inputs. Below is a description of the key bindings and what each key does.

## Key Bindings

### Movement Controls
- **W / w / UP Arrow**: Move the current instance up
- **A / a / LEFT Arrow**: Move the current instance left
- **S / s / DOWN Arrow**: Move the current instance down
- **D / d / RIGHT Arrow**: Move the current instance right

### Rotation Controls
- **Q / q / F2**: Increment the angle of the current instance
- **E / e / F3**: Decrement the angle of the current instance

### Instance Controls
- **C / c / F1**: Create a new instance and select it
- **1 / Page Up**: Select the next instance
- **3 / Page Down**: Select the previous instance

### Scaling Controls
- **F / f / F5**: Increment the scale of the current instance
- **G / g / F6**: Decrement the scale of the current instance

## Program Capabilities

- **Create and manage multiple house instances**: You can create new house instances and switch between them using the provided key bindings.
- **Move instances**: Use the movement controls to move the selected house instance in the 2D space.
- **Rotate instances**: Use the rotation controls to rotate the selected house instance.
- **Scale instances**: Use the scaling controls to change the size of the selected house instance.
- **Reset instances**: Reset the parameters of the selected house instance to their default values.

### Outras Funcionalidades

- **R / r / Insert**: Reset the parameters of the current instance
- **ESC**: Exit the program

## Compilação e Execução

Para compilar e executar o aplicativo, utilize o `Makefile`.

```sh
make
make run
make clean