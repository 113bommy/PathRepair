n = int(input())

def open(s):
    st = []
    n = len(s)
    for i in range(n):
        if (s[i] == '('):
            st.append(s[i])
        if (s[i] == ')'):
            if (len(st) == 0):
                st.append(')')
            elif (st[-1] == '('):
                st.pop()
            else:
                st.append(')')
    S = ""
    for i in st:
        S += i
    return S
d = {}
r = 0
a = []
for i in range(n):
    S = input()
    b = open(S)
    if (b == ""):
        r += 1
    else:
        c1 = 0
        c2 = 0
        for j in b:
            if j == ')':
                c1 += 1
            else:
                c2 += 1
        a.append((c1, c2))
        d[(c1, c2)] = 0
        d[(c2, c1)] = 0
for i in a:
    d[i] += 1
res = r / 2
for i in a:
    if (i[0] > 0 and i[1] > 0):
        continue
    if (d[i[:2][::-1]] > 0 and d[i[:2]] > 0):
        d[i[:2][::-1]] -= 1
        d[i[:2]] -= 1
        res += 1
            

print(res)
