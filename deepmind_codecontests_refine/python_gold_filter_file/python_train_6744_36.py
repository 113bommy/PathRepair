N = int(input())
A = list(map(int,input().split()))
E = [0]*N
for e in A:
    E[e-1] += 1
print(*E,sep="\n")
