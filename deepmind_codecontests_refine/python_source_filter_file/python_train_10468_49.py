_=input()
__=0
if (_[0] in "ah" and _[1] in "18"):
     __=3
elif (_[0] in "bcdef" and _[1] in"18" ) or (_[0] in "ah" and _[1] in "234567"):
     __=5
else:
     __=8
print(__)