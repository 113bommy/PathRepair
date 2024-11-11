n = int(input())
l = list(map(int, input().split()))
ans = 0

for i in range(n):
    if l[i] > ans + 15:
        break
    else:
        ans = l[i]

if ans > 89:
    print(90)
else:
    print(ans+15)    