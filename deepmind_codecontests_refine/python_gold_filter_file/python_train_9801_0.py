n = int(input())
a = [int(x) for x in input().split()]
a = sorted(a)
m = int(input())
q = [int(x) for x in input().split()]
s = sum(a)
for i in range(m):
    ans = s - a[n-q[i]]
    print(ans)

