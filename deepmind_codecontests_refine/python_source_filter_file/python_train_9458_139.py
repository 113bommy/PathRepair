#C問題
import re
S = str(input())
p = re.match('(dream|dreamer|erase|eraser)+$',S)
if p:
    print("Yes")
else:
    print("No")