# Stats Plugin
A system that is used to easily manage different character stats

## Installation
1. Download the latest release from GitHub
2. Navigate to `C:\Program Files\Epic Games\UE_{VERSION}\Engine\Plugins\`
3. Create a `Marketplace` folder if needed
4. Extract the release and copy to the `Marketplace` folder
5. Open Unreal Engine
6. Click on `Edit > Plugins`
7. Enable the plugin under the `Installed > Unreal Toolbox` category
8. Restart Unreal Engine

## Stat Component
A `Stat Component` can be added to each actor that requires the use of stats. The following properties can be changed inside the editor:
1. `Max Value` - The maximum value of the stat
2. `Regenerate` - The amount of value regenerated in a second

## Interacting with the Stat Component
You can interact with a `Stat Component` by using the following functions:
1. `Get Value` - Return the current value of the stat
2. `Update Value` - Set the value of the stat (clamped between 0 and the max value)
3. `Get Max Value` - Return the maximum value of the stat
4. `Set Max Value` - Set the maximum value of the stat
5. `Get Regenerate Amount` - Return the amount of value regenerated in a second
6. `Set Regenerate Amount` - Set the amount of value regenerated in a second

## Stat Component Events
There is 2 different events in a `Stat Component`:
1. `On Value Updated` - Called every time the value of the stat is updated
2. `On Value Zero` - Called when the value of the stat reaches zero