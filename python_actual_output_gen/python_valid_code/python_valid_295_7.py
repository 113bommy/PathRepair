a = int(input())
i = 1
while i * i <= a:
    i += 1
i -= 1
ans = i * 4
if a % (i * i) == 0:
    print(ans)
elif a % (i * i) <= i:
    print(ans + 2)
elif a % (i * i) <= 2 * i:
    print(ans + 4)
