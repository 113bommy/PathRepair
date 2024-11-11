S = input()
import re
if re.match("(dream|dreamer|erase|erase)*$", S):
    print("YES")
else:
    print("NO")