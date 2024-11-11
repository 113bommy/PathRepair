s = input()
ko = 0
kek = 0
d = ""
for i in range(len(s)):
    if s[i] == 1 and kek == 0 or kek == 1:
        kek = 1
        d+=s[i]

for i in range(len(d)):
    if d[i] == '0':
        ko += 1

if ko >= 6:
    print("yes")
else:
    print("no")
