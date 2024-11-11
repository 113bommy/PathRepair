n = int(input())
a = list(map(int, input().split()))
i = -1
j = n
s1, s2 = 0, 0
ans = 0
while i <= j:
    if s1 == s2:
        ans = max(ans, s1)
    if s1 >= s2:
        j -= 1
        s2 += a[j]


    else:
        i += 1
        s1 += a[i]


print(ans)