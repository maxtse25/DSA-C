/* Do rotation under the four cases:
case 0: Z = root
case 1: Z.uncle = red -> recolor
case 2: Z.uncle = black(triangle) -> rotate Z.parent
case 3: Z.uncle = black(line) -> rotate Z.grandparent & recolor

Time complexity:
Insert: O(log n)
Color red: O(1)
Fix violations:
    Constant # of:
        a. Recolor: O(1)
        b. Rotation: O(1)
*/

// Right Rotation
// Left Rotation
// Insertion
/* Deletion 
1. Transplate: hleps move subtrees within the red-black tree
2. Delete
3. Delete_fixup
*/