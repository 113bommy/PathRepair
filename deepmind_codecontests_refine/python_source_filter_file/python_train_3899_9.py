n, v = map(int, input().split())
l = [0]*(3010)
ans = 0
for i in range(n):
    a, b = map(int, input().split())
    l[a] = b
day = 1
for i in range(3004):
    temp = min(v, l[day-1])
    ans += temp
    l[day-1] -= temp
    rem = v - temp
    temp2 = min(rem, l[day])
    ans+=temp2
    l[day]-=temp2
    day+=1

print(ans)