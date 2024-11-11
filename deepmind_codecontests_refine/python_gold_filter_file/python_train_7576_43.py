import fractions

n = int(input())
a = list(map(int, input().split()))

l = a[0]
for i in range(1, n):
    l = l * a[i] // fractions.gcd(l, a[i])

count = 0


for i in a:
  count += l//i
count %= (10**9+7)

print(count)