a,b,c = map(int, input().split())
l = 0
for i in range(a,b+1):
    if c % i == 0:
        l += 1
print(l)
