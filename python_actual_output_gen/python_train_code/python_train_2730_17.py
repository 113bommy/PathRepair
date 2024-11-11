s = str(input())
l = 0
r = 0
s = s.replace(" ", "")
sl = ""
sr = ""
b = True


for i in range(len(s)):
    if s[i] == '^':
        b = False
        continue
    if b:
        sl += s[i]
    else:
        sr += s[i]

sl =sl[::-1]
for i in range(len(sl)) :
    if sl[i]!="=":
        l+=(i+1)*int(sl[i])
for i in range(len(sr)) :
    if sr[i]!="=":
        r+=(i+1)*int(sr[i])

if l>r:
    print("left")
if r==l:
    print("balanced")
if l<r: print("right")
