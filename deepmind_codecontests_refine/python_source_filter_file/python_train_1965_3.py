import sys
a=[0,0,1]+[1,0]*5*10**5
for i in range(4,999):
 if a[i]:a[i*2::i]=[0]*len(a[i*2::i])
for e in sys.stdin:print(sum(a[:int(e)+1]))
