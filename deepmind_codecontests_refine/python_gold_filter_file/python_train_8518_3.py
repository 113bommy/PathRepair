s=input()
import re
if re.fullmatch("A?KIHA?BA?RA?",s) is not None:
        print("YES")
else:
        print("NO")