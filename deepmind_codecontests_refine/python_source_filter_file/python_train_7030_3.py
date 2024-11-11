sir = input()
l = [x for x in sir]
l.append('1')
n = len(l)
for i in range(n - 1):
    if l[i] == l[i + 1]:
        if l[i + 1] == l[i + 2]:
            if l[i + 1] != 'z':
                l[i + 1] = chr(ord(l[i + 1]) + 1)
            else:
                l[i + 1] = 'a'
        else:
            if l[i] != 'z':
                l[i] = chr(ord(l[i]) + 1)
            else:
                l[i] = 'a'
    if l[i] == l[i - 1]:
        if l[i-1] != 'z':
            l[i-1] = chr(ord(l[i-1]) + 1)
        else:
            l[i-1] = 'a'

sol = str()
for x in range(n - 1):
    sol += l[x]
print(sol)
