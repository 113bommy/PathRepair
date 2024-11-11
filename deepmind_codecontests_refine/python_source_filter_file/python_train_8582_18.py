import re
E='eon'
l=['vapor','jolt','flar','esp','umbr','leaf','glac','sylv']
input()
p=input()
print(next(s+E for s in l if re.match(p, s+E)))
