n = int(input())
l = [int(x) for x in input().split(" ")]
l.sort()
tim = 0
ans = 0
for i in range(n):
    if not(tim>l[i]):
        ans += 1
        tim += l[i]
print(ans)