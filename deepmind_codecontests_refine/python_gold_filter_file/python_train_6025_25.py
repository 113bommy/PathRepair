n, l = map(int,input().split())
a = list(map(int,input().split()))

loc = -1
for i in range(n-1):
    if a[i] + a[i + 1] >= l:
        loc = i + 1
        break

if loc < 0:
    print("Impossible")
    exit()

print("Possible")

for i in range(1, loc):
    print(i)
for i in range(n - 1, loc - 1, -1):
    print(i)
