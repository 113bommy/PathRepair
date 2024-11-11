n = int(input())
a = list(map(int, input().split()))
d = sum(a)//2
c = 1
for x in a:
  c |= c << x
c >>= d
for i in range(d+5):
  if c & (1 << i):
    print(d+i)
    break