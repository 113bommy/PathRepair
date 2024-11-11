import fractions

mod = 10**9 + 7;

N = int(input())
A = list(map(int, input().split()))

l = 1
for i in A:
  l = l * i // fractions.gcd(l, i)

sum = 0
for i in A:
  sum += l // i

print(sum % mod)