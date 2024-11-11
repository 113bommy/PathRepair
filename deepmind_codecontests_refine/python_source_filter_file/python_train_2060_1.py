N = list(input())
ans = 0
temp = [0] + [int(n) for n in N]
for i in reversed(range(1, len(N)+1)):
    if temp[i] < 5 or (temp[i] == 5 and temp[i+1] < 4):
        ans += temp[i]
    else:
        temp[i+1] += 1
        ans += (10 - temp[i])
        temp[i] = 0
ans += temp[0]
print(ans)