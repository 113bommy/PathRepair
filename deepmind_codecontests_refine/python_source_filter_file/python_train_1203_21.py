s = input()
v = ['A', 'E', 'I', 'O', 'U', 'Y']
l = [0]
for i in range(len(s)):
    if s[i] in v:
        l.append(i+1)
l.append(len(s))
d = [l[x+1]-l[x] for x in range(len(l)-1)]
print(max(d))

'''
ABABBBACFEYUKOTT
4

AAA
1

'''
