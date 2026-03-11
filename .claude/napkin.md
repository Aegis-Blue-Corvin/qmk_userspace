# Napkin Runbook

## Curation Rules
- Re-prioritize on every read.
- Keep recurring, high-value notes only.
- Max 10 items per category.
- Each item includes date + "Do instead".

## Execution & Validation (Highest Priority)
1. **[2026-03-11] BastardKB userspace is keymap-per-keyboard, no users/ dir**
   Do instead: Place all keymap files directly in `keyboards/bastardkb/{board}/keymaps/{name}/`. No miryoku userspace framework.

2. **[2026-03-11] Bilateral combinations not available in BastardKB QMK fork**
   Do instead: Use only standard QMK tapping settings (TAPPING_TERM, QUICK_TAP_TERM). Comment out bilateral combination defines for reference.

3. **[2026-03-11] qmk.json controls GitHub Actions build targets**
   Do instead: Only list keyboards/keymaps you actually want to build. Remove unused vendor targets for faster CI.

## Domain Behavior Guardrails
1. **[2026-03-11] Charybdis 3x5 LAYOUT expects exactly 35 keys**
   Do instead: 30 alpha keys (3 rows × 10 cols) + 5 thumb keys (3 left, 2 right — trackball replaces right third thumb).

2. **[2026-03-11] POINTING_DEVICE_RIGHT must be set for Charybdis trackball**
   Do instead: Always include `#define POINTING_DEVICE_RIGHT` in config.h for right-hand trackball builds.

## User Directives
1. **[2026-03-11] Keep corvins_files/ as reference archive of old miryoku setup**
   Do instead: Don't modify or delete corvins_files/. Active keymap lives in keyboards/bastardkb/charybdis/3x5/keymaps/corvin-keymap/.
