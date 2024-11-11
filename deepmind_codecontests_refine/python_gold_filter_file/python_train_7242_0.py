from collections import *
s=input()
c=Counter(s)
print(min(c['B'],c['a']//2,c['u']//2,c['b'],c['l'],c['s'],c['r']))
