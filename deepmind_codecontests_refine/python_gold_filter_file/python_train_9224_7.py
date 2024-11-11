n = int(input())
s,k = [],[]
for i in range(n):
    l = str(input())
    if l in k:
        s.append("YES")
    else:
        s.append("NO")
    k.append(l)
for i in range(len(s)):
    print(s[i])