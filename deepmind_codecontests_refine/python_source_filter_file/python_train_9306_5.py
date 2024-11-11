d = list(map(int,input().split()))

l = list(map(int, input().split()))

l.sort()
t = 0
for i in range(0, len(l) - 1):
    j = i
    while abs(l[j] - l[j+1]) <= d[1]:
        t += 2
        j += 1
        if j == len(l) - 1:
            break

print(t)

# 1512820898759
