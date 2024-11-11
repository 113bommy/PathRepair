N=int(input())
H=[int(x) for x in input().split()]
cur=[0]*N
for i in range(N):
    if H[i]<=H[i-1]:
        cur[i]=cur[i-1]+1
print(max(cur))
