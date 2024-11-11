I = input()

import re
if re.match("^(dream|dreamer|erase|eraser)+$", I):
    print("YES")
else:
    print("NO")
