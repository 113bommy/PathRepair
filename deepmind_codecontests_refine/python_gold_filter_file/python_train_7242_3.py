s=input()
ref="Bulbasaur"
from collections import Counter 
c=Counter(s)
print(min(c['B'],c['u']//2,c['l'],c['b'],c['s'],c['r'],c['a']//2))