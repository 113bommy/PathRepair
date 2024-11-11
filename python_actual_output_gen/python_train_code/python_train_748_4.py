n = int(input())
a = map(int,input().split())
mod = 10**9 + 7
temp = sum(a)**2
for x in a:
  temp -= x**2
print((temp//2)%mod)