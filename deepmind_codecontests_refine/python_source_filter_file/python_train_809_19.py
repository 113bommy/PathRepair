import itertools
N=int(input())
an=[int(x) for x in map(int,input().split()[:N])]

ret=an[0]
for x in range(1,N):
    ret= ret[x] ^ ret

if ret==0:
    print("Yes")
else:
    print("No")
