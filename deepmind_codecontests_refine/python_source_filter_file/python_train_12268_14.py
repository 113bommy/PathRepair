import collections
N = int(input())
D = collections.Counter(list(map(int,input().split())))
M = int(input())
T = collections.Counter(list(map(int,input().split())))
for x in T:
    if D[x]<T[x]:
        print('NO')
        break
else:
    print('Yes')