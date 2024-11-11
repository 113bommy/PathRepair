n, k = [int(x) for x in input().split()]
r = [int(x) for x in input().split()]
for i in range(1,2*n+1,2):
    if r[i]>r[i-1]+1 and r[i]>r[i-1]+1 and k>0:
        r[i] -= 1
        k -= 1
print(*r)