#n = int(input())
n, k, m = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
b = [0] * m
a = [ [] for i in range(m)]
p = set()
for i in range(n):
    l = c[i] % m
    a[l].append(c[i])  
    b[l] += 1
l = max(b)
if l >= k:
    print("Yes")
    print(*a[b.index(l)][0:k])
else:
    print("No")
    