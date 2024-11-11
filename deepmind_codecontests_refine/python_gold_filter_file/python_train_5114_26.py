n = int(input())
l = list(map(int, input().split()))
ans = 0

for i in range(len(l) - 2):
    if l[i] == 1 and l[i + 1] == 0 and l[i + 2] == 1:
        l[i + 2] = 0
        ans += 1
print(ans)







