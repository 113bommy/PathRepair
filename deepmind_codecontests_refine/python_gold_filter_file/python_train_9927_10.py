n = int(input())
lis = list(map(int, input(). split()))
sor = sorted(lis)
cnt = 0
for i in range(n):
    if lis[i] != sor[i]:
        cnt += 1
if cnt > 2:
    print("NO")
else:
    print("YES")