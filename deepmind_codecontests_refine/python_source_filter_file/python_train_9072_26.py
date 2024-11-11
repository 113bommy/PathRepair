n = int(input())
ans = 0
# distance of piece marked i and j must be higher than j - i
dist = []
for i in range(1, 1000):
    if 2*i <= 999:
        dist.append(2*i)
    else:
        break
if n == 1:
    ans = 1
else:
    for i in range(len(dist)):
        if dist[i] >= n-1:
            ans = i+2
            break
if ans == 1:
    print(1)
    print("1 1")
else:
    print(ans)
    for i in range(1, ans+1):
        if n == 0: break
        print(1, i)
        n -= 1
    for i in range(2, ans+1):
        if n == 0: break
        print(i, ans)
        n -= 1