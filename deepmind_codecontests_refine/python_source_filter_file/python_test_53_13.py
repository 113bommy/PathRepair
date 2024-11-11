from collections import Counter, defaultdict
import sys
readline=sys.stdin.readline

T=int(readline())
for _ in range(T):
    N,c=readline().split()
    N=int(N)
    S=readline().rstrip()
    if S.count(c)==N:
        print(0)
        continue
    for i in range(N):
        if (i+1)*2>N and S[i]==c:
            print(1)
            print(i)
            break
    else:
        print(2)
        print(N,N-1)