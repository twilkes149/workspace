# Intro
This project is a workspace project. You will be able to define different "workspaces". Each workspace will consist of a list of softwares and programs a user might use. A user might have a workspace for a job and then another workspace for home use. A user will be able to define a workspace (name it), add software to that workspace. Then when the user logs in, they will be able to select which workspace they want to open.

# Design
## Part 1
Part one will just consist of defingin workspaces, being able to see a list of saved workspaces, and finally the software will open all the programs defined in a workspace.
### Workspace object
- name
- list of programs
<br>
Functionality:
Create a workspace from a json string
add / remove programs from a workspace
Save a workspace to a file

### Program object
- program name
- path to executable

## Part 2
In part two the user will be able to see a list of installed programs and select which ones they want to add to a workspace. This will automatically add the path.