n, m = map(int, input().split())

v = [-1 for i in range(n)]
li = [int(i)-1 for i in input().split()]
print(li)

for i in range(m):
    for j in range(li[i], n):
        if v[j] == -1:
            v[j] = li[i]+1

print(*v)