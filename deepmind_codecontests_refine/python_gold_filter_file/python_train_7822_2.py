n = int(input())
a = list(map(int, input().split()))
c = 0
l = 0
r = n - 1
ans = []
while len(ans) != n:
    if l < n and (a[r] >= a[l] or a[r] < c) and a[l] > c:
        ans.append("L")
        c = max(a[l], c)
        l += 1
    elif r > -1 and a[r] > c:
        ans.append("R")
        c = max(a[r], c)
        r -= 1
    else:
        break
print(len(ans))
print("".join(ans))