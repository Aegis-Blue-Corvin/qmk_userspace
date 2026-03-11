# Charybdis Nano (3x5) `corvin-keymap`

Custom 4-layer keymap for the Charybdis Nano, based on Miryoku principles.

## Layers

- **BASE** - QWERTY with GACS home row mods
- **FUN** - Function keys (left), German characters and media controls (right)
- **NAV** - Number pad layout (left), arrow keys and navigation (right)
- **MOUSE** - Shifted symbols (left), mouse buttons and scroll (right)

## Features

- Home row mods (GUI, Alt, Ctrl, Shift) on the base layer
- German characters (ü, ä, ö, ß) accessible via RAlt on FUN/NAV/MOUSE right hand
- Caps Word toggle on NAV and MOUSE layers
- Auto-sniping on the MOUSE layer
- Drag scroll support
- Custom string macros (QNR, TSS, TXT, SRCH, EXT)

## Thumb keys

| Left 1 | Left 2 | Left 3 | Right 1 | Right 2 |
|--------|--------|--------|---------|---------|
| FUN/Esc | NAV/Space | MOUSE/Tab | FUN/Enter | NAV/Bksp |

## Building

### GitHub Actions

Push to your fork and the workflow will build automatically (ensure `qmk.json` includes this keymap).

### Local

```sh
qmk compile -c -kb bastardkb/charybdis/3x5 -km corvin-keymap
```
