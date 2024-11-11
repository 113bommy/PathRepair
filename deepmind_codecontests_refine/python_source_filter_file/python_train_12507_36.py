N = int(input())
L = [tuple(map(int,input().split())) for i in range(N)]
k = int(input())
for i,x in enumerate(L):
    if k<x[1] :break
print(N-i)