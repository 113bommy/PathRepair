N,M = list(map(int, input().split()))
 
s = [list(map(int,input().split())) for i in range(N)]
c = [list(map(int,input().split())) for j in range(M)]
 
for t1 in s:
    l = list(map(lambda x: abs(t1[0] - x[0]) + abs(t1[1] - x[1]), c))
    print(l.index(min(l)) + 1)