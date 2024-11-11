from sys import stdin,stdout
from collections import Counter
n,k=input().strip().split(' ');n,k=int(n),int(k)
boxes=list(map(int,stdin.readline().strip().split(' ')))
def mo(x):
	global k
	return x%k
boxes=Counter(list(map(mo,boxes)))
ans=0;
if 0 in boxes:
        ans+=boxes[0]//2

if k%2==0:
    for i in range(1,k//2):
        if i in boxes and (k-i) in boxes:
            ans+=min(boxes[i],boxes[k-i])
    if k//2 in boxes:
        ans+=boxes[k//2]//2
else:
    for i in range(1,k//2+1):
        if i in boxes and (k-i) in boxes:
            ans+=min(boxes[i],boxes[k-i])

print(ans*2)
