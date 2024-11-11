n, t = map(int,input().split())
s1 = input()
s2 = input()
p1 = n - t
p2 = n - t
s = [' ' for i in range(n)]
c = "abcdefghtyux"
for i in range(n):
    if(s1[i] == s2[i] and p1 > 0 and p2 > 0):
        s[i] = s1[i]
        p1 -= 1
        p2 -= 1
for i in range(n):
    if p1 > 0 and s[i] == ' ':
        p1 -= 1
        s[i] = s1[i]
    elif p2 > 0 and s[i] == ' ':
        p2 -= 1
        s[i] = s2[i]
if p1 == 0 and p2 == 0:
    for i in range(n):
        if s[i] == ' ':
            for x in range(len(c)):
                if(c[x] != s1[i] and c[x] != s2[i]):
                    s[i] = c[x]
                    break
    print(''.join(str(p) for p in s))
else: print("-1")
