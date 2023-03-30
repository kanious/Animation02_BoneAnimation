1. How to build the project

- Please set "BoneAnimation" project as a starter project and build with x64 configuration / Debug or Release mode.
  Or you can execute with "BoneAnimation.exe" file in x64\Debug(or Release) folder.

- GitHub Link:
https://github.com/kanious/Animation02_BoneAnimation



2. User Input Option

- You can see all options in the UI in game.

- How to move the player:
1) "Mouse LB Click" the tile to set a goal
2) Press "F1" to move the player
3) The player will move with "Run" animation, and change to "Idle" animation when he arrives at the goal.

* F2 : Toggle camera mode (Free mode <-> Follow mode)
* F3 : Toggle Animation Blending Mode (On/Off)
* ESC : Close the program.

< For changing multiple animations >
* 1 : Walk
* 2 : Run
* 3 : Attack 1
* 4 : Attack 2
* 5 : Grab
* 6 : Pick up
* 7 : Hurt
* 8 : Death
* Not Pressing : Idle
(Animations do not change while the player is moving.)

< For showing debug color >
* 0 : Color vertices according to their assigned bones

< For Camera (Only for free mode) >
* WASD : Move Camera
* QE : Rotate Camera (90 degree per pressing)
* Mouse wheel drag : Zoom In/Out



3. Simple Description

In the follow mode, the camera is locked in front of the character.

Code related to mesh and animation loading:
  PumpkinEngine > 04.Component > Mesh > Mesh class (Ready_Assimp function)
  PumpkinEngine > 05.IndependantFunctions > Animation > Animation class (Ready function)

Shader file (file path):
  (SolutionDir) > x64 > Assets > Shader > BoneVertex.fx / BoneFragment.fx
 

