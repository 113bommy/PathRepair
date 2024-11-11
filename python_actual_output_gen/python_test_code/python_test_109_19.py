n = int(input())
a = list(map(int, input().split()))
m = 1
for i in a:
    m *= i
    if m > 10**18:
        m = -1
        break
print(m)
