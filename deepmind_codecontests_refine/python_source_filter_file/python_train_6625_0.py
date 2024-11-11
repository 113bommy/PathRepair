s1 = list(input())
s2 = list(input())

l = [[0]*26]*(len(s1)+1)
l[-1] = [-1]*26
for i in range(len(s1)- 1, -1, -1):
    l[i] = list(l[i+1])
    l[i][ord(s1[i]) - ord('a')] = i


ans = 1
n = 0
for i in range(len(s2)):
    if n >= len(s1):
        n = 0
        ans += 1
    m = l[n][ord(s2[i])- ord('a')]
    if m == -1:
        ans += -1
        m = l[0][ord(s2[i])- ord('a')]
        if m == -1:
            print(-1)
            exit()
    n = m+1
print(ans)