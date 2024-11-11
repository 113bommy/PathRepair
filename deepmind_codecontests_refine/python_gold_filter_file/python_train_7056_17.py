s=input()
q=int(input())
from collections import deque
qq=deque(s)
cnt=0
for i in range(q):
    j=input()
    if j=="1":
        cnt+=1
        continue
    _,k,l=j.split()
    if (k=="2")^cnt%2:
        qq.append(l)
    else:
        qq.appendleft(l)

if cnt%2==1:
    print("".join(reversed(list(qq))))
else:
    print("".join(qq))