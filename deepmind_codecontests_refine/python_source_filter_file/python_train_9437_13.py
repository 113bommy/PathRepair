from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
from collections import Counter
lst = lambda: list(map(int, stdin.readline().split()))
for _ in range(1):
    s=input()
    n=len(s)
    d=Counter(s)
    f=1;cnt=0
    for k,v in d.items():
        if v==1:
            cnt+=1
    if (len(d)==2 and cnt==0):print('YES')
    elif (3==len(d) and cnt<=1):print('YES')
    elif (len(d)==4):print('YES')
    else:print('NO')