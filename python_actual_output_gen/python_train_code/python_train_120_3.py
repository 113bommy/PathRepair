def primfacs(n):
   i = 2
   primfac = []
   while i * i <= n:
       while n % i == 0:
           primfac.append(i)
           n = n // i
       i = i + 1
   if n > 1:
       primfac.append(n)
   return primfac
n, m = map(int, input().split())
if n == m:
    print(0)
    exit()
nn, mm = primfacs(n), primfacs(m)
a, b = set(nn), set(mm)
c = a ^ b
if not(c <= {2, 3, 5}):
    print(-1)
    exit()
ans = 0
for i in c:
    ans += abs(nn.count(i) - mm.count(i))
print(ans)