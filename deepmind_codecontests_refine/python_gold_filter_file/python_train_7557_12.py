l = input()
s = input()
n = int(input())
a = []
for _ in range(n):
    c = input()
    nl = s
    if '*' in nl:
        if len(nl) <= len(c):
            nl = nl.replace('*', '*'*(abs(len(nl)-len(c))+1))
        elif len(nl)==len(c)+1:
            nl = nl.replace('*', '')
    if len(c)!=len(nl):
        a.append("NO")
    else:
        for i in range(len(c)):
            if nl[i] == '*':
                if c[i] in l:
                    a.append("NO")
                    break
            elif nl[i] == '?':
                if c[i] not in l:
                    a.append("NO")
                    break
            else:
                if nl[i] != c[i]:
                    a.append("NO")
                    break
        else:
            a.append("YES")
for i in a:
    print(i)
