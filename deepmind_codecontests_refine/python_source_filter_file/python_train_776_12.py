n = list(map(int, input()))
ans = []
k = len(n)
#print(k, n)
while sum(n) != 0:
    now = ""
    for i in range(k):
        if n[i] != 0:
            now += "1"
            n[i] -= 1
        else:
            now += "0"
    ans.append(now)
print(len(ans))
print(*ans)