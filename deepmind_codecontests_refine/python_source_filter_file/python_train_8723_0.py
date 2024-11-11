N = int(input())
a = [int(i) for i in input().split()]
t = sum(a)-2*sum(a[1::2])
b = [t]
for i in range(1,N+1):
    t = 2*a[i-1] - t
    b += [t
print(*b[:N])