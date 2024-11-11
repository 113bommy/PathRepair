n = int(input())
c = 0
for i in range((int(n ** 0.5)) + 2):
    if n == (i *(i + 1)) // 2:
        c += 1
        break
if c > 0:
    print("YES")
else:
    print("NO")