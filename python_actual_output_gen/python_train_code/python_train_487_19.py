n = int(input())
m = [int(x) for x in input().split()]
s = sum(m) + 1
w = 0
for i in range(1,6):
    if (i + s) % (n+1) > 0:
        w += 1
print(w)