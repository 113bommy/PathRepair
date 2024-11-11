n = int(input())
target = list(map(int,input().split()))
got = list(map(int,input().split()))
swaps = []
for i in range(n-1,-1,-1):
    for j in range(i+1):
        if got[j] == target[i] and j != i:
            swaps.append((j,j+1))
            got[j],got[j+1] = got[j+1],got[j]
print(len(swaps))
for i in swaps:
    print(*i)
