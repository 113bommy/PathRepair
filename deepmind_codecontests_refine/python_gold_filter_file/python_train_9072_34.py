n = int(input())

m = n//2 + 1
print(m)
r = 0
c = 1
for i in range(n):
    if i % 2 == 0:
        r += 1
    else:
        c += 1
    print(r,c)
