n = int(input())
a = [int(x) for x in input().split()]
m = int(input())
b = [int(x) for x in input().split()]

ans = []
for i in range(n):
    for j in range(m):
        if b[j] % a[i] == 0:
            # print(b[j], a[i])
            ans.append(b[j] / a[i])

print(ans.count(max(ans)))
