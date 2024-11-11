N = int(input())
ans = -1
bef = -1
for i in range(N):
    now = int(data[input()])
    if now - bef > 1:
        ans = -1
        break
    elif now - bef == 1:
        ans += 1
        bef = now
    else:
        ans += now
        bef = now

print(str(ans))