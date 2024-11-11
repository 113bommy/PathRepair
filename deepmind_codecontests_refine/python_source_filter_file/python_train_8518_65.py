S=input()
import re
m = re.match(r'A*KIHA*BA*RA*', S)
print("YES" if m is not None else "NO")
