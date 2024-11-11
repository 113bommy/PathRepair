s1 = input()
s2 = input()
k = len(s2)
l = -1
m = 0
for i in range(k):
    if s2[i] != s1[i]:
        l = i
        break
for i in range(k - 1, l, -1):
    if s2[i] != s1[i + 1]:
        m = 1
        break
if m and l != -1:
    print(0)
else:
    if l == -1 and m == 1:
        print(1)
        print(k + 1)
    else:
        if l == -1:
            l = 1
        i = l - 1
        ans = [l + 1]
        while i > -1 and s1[i] == s1[l]:
            ans.append(i + 1)
            i -= 1
        i = l + 1
        while i < k + 1 and s1[i] == s1[l]:
            ans.append(i + 1)
            i += 1
        print(len(ans))
        print(*sorted(ans))