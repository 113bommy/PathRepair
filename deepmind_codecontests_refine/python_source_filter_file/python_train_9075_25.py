from collections import Counter
import sys
import math
n=input()
a=['4','7']  
c=Counter(n)
#print(c)
maax=max(c['4'],c['7'])
if(c['4']==0 and c['7']==0):
    print(-1)
elif(c['4']>=c['7']):
    print(4)
elif(c['4']<c['7']):
    print(4)
