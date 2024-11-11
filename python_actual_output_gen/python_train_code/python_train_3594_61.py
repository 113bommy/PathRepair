k, n, w = map(int, input().split())
tot = 0
for i in range(1,w+1):
    tot += i*k
print(tot)
if n > tot:
    print(0)
else:
    print(tot - n)