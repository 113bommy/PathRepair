n = int(input())
m = [int(x) for x in input().split()]
r = [int(x) for x in input().split()]
count = 0
for i in range(40000):
    for j in range(n):
        if i % m[j] == r[j]:
            count += 1
            break
print(count / 40000)
