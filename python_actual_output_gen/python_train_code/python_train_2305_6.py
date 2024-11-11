n = int(input())

a = [int(_) for _ in input().split()]


if sum(a) % (n*(n+1)//2) != 0:
    print("NO")
    exit()

m = sum(a)//(n*(n+1)//2)
# print(m)
d = [a[i]-a[i-1]-m for i in range(n)]

# print(d)
for D in d:
    if D % n == 0:
        m += D//n
    if D % n != 0 or D < 0:
        print("NO")
        exit()
if m == 0:
    print("YES")
else:
    print("NO")
