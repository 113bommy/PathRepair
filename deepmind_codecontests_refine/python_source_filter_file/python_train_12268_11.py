from collections import defaultdict

N=int(input())
d = defaultdict(int)
for D in input().split():
    d[D]+=1
M=int(input())
T=[int(i) for i in input().split()]

for t in T:
    if d[t]>=1:
        d[t]-=1
    else:
        print('NO')
        exit()
print('YES')