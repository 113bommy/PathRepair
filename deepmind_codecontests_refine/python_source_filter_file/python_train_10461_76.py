a = list(map(int , input().split()))
p = 0
for i in range(a[2]):
    p = p + a[0]*(i+1)
if p - a[1]:
    print(p - a[1])
else:
    print(0)
    