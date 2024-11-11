n = int(input())
a = list(map(int, input().split()))
b = []

b.append(sum(a) - 2*sum(a[1:n-1:2]))
i = 0
while i < n-1:
    b.append(2*a[i]-b[i])
    i += 1

print(*b)