# QMK Userspace

This is the QMK Userspace for the Bastard Keyboards keymaps.

You can read how to compile your own keymap on the official docs here: [https://docs.bastardkb.com/fw/compile-firmware.html](https://docs.bastardkb.com/fw/compile-firmware.html).

---
full text from that website:

Table of contents
Table of contents
Introduction
Pre-requisites
BastardKB userspace
Creating your keymap
Compiling your firmware using Github actions
Pre-requisites
Compiling your firmware
Compiling your firmware using the local command line
Pre-requisites
Working QMK environment
BastardKB QMK fork
QMK Userspace
Compiling your firmware
{keyboard} argument
{keymap} argument
Flashing your keyboard
Introduction
The BastardKB QMK repository contains the behavioral firmware code and releases for the Bastard Keyboards Charybdis boards.

The keymaps are stored in the BastardKB QMK userspace repository.

The QMK repository repository is used as primary source of truth for Bastard Keyboards firmwares and contains the latest changes and improvements. The maintainers aim at upstreaming all those changes to the official QMK repository.

This page details how to build your own firmware. Building from source is useful to people who want to customize their keyboard and keymaps beyond what Via offers. You will have to modify the keymap C code, and from there compile your firmware either using Github actions or the local command line.

If that seems too complicated, you can also use one of the release firmware builds.

If you are compiling for the Dilemma V3/Dilemma MAX V3, you can check the specific instructions here.

Pre-requisites
BastardKB userspace
While the QMK repository contains the logic behind the keyboards, the keymaps are in the userspace repository.

If you are going to create your own keymaps, the first step is to fork the BastardKB QMK userspace repository.

This way, you can:

track changes
use Github actions to compile your keymap
(if relevant) contribute your keymap to the origin Bastard KB QMK Userspace
In a separate folder, clone the fork you just created, using either Github desktop or the command line:

git clone https://github.com/my_username/qmk_userspace 

Creating your keymap
If you want to create your own keymap, make sure you have forked the BastardKB QMK userspace repository.

Create a separate folder in the relevant folder, eg:

keyboards/bastardkb/charybdis/4x6/keymaps/my-keymap/

By convention, your keymap name must be all lowercase, without spaces.

Then, the easiest is to copy over an existing keymap (eg. vendor) over, and modify from there.

Compiling your firmware using Github actions
By using github actions, you can have Github compile your firmware without having to bother with a local QMK installation and console commands.

Pre-requisites
If you want to use Github actions to compile your firmware (rather than doing it locally in the console), you will need to:

fork the BastardKB QMK userspace repository
in the Actions tab, enable workflows
Compiling your firmware
First, make sure you have gone through the Github actions requirements section above.

After cloning the BastardKB userspace repository, it is already configured to work with the BastardKB QMK fork - so no need for additional configuration on that side.

Once you created your own keymap, you will need to add it to the list of keymaps to be compiled in qmk.json, for example:

{
    "userspace_version": "1.0",
    "build_targets": [
        ["bastardkb/charybdis/4x6", "my-keymap"]
    ]
}

We also recommend deleting the other keymaps if you don’t use them, as it’ll make the action run faster.

Then,

Push your changes above to your forked GitHub repository
Look at the GitHub Actions for a new actions run
Wait for the actions run to complete
Inspect the Releases tab on your repository for the latest firmware build
Compiling your firmware using the local command line
You can also compile your firmware through your local command line. This requires you to be familiar with the console, and doing some additional configuration.

Pre-requisites
Working QMK environment
Make sure you have a functional QMK environment. See QMK Docs for details. At this point, you don’t need to run qmk setup.

BastardKB QMK fork
Clone the BKB QMK repository, using either github desktop or the command line, and switch to the bkb-master branch:

git clone https://github.com/bastardkb/bastardkb-qmk
cd bastardkb-qmk
git checkout -b bkb-master origin/bkb-master
qmk git-submodule

Now that you’ve cloned the repository, set it as the default local QMK repository. You also need to do this if you had a previous, separate QMK installation.

qmk config user.qmk_home="$(realpath .)" 

If you have multiple QMK installations, you will need to manually set the qmk home path again to use the other ones.

That’s all you needed to do with the QMK repository. From here on, we will only focus on the userspace repository.

QMK Userspace
Next, cd into your userspace fork and enable userspace:

qmk config user.overlay_dir="$(realpath .)"

Compiling your firmware
Once in the QMK userspace repository, compiling a keymap works the same as normal:

qmk compile -c -kb bastardkb/{keyboard} -km {keymap}

{keyboard} argument
{keyboard} corresponds to the physical keyboard you are building the firmware for. It can be one of the following:

charybdis/4x6: the 4x6+5 Charybdis
charybdis/3x5: the 3x5+3 Charybdis Nano
charybdis/3x6: the 3x6+3 Charybdis Mini
scylla: the 4x6+5 Scylla
skeletyl: the 3x5+3 Skeletyl
tbkmini: the 3x6+3 TBK Mini
dilemma/3x5_3: the 3x5+3 Dilemma
dilemma/4x6_4: the 4x6+4 Dilemma Max
{keymap} argument
{keymap} corresponds to the keymap that you created.

If you followed the instructions until now, it would be my-keymap.

Flashing your keyboard
Once you compiled your uf2 image, you can flash your keyboard.

For how to flash your keyboard, take a look at the how to flash your keyboard page.