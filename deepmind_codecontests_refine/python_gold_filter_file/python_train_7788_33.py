n = int(input())
V = list(map(int,input().split()))
even = [0] * 100001
odd  = [0] * 100001

for v in V[1::2]:
    even[v] += 1
for v in V[::2]:
    odd[v]  += 1
maxeven = max(even)
maxodd  = max(odd)
if(even.index(maxeven) != odd.index(maxodd)):
    print(n - maxeven - maxodd)
else:
    even.sort()
    odd.sort()
    print(min(n-even[-1]-odd[-2],n-even[-2]-odd[-1]))