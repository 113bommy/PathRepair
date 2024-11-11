s = input()
g = 'aeoiu'
if len(s) == 1:
    if s in g+'n': print("YES")
    else: print("NO")
    exit()
s += '.'
r = ""
for i in range(len(s)-1):
    r += s[i]
    if s[i] == 'n' and s[i+1] not in g:
        r += 'a'
for i in range(len(r)-1):
    if r[i] not in g and r[i+1] not in g: 
        print("NO")
        exit()
print("YES")
