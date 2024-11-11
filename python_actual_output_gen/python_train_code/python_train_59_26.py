import sys
c,r = 0, 0
for s in sys.stdin.readlines():
    if s[0]=="+": c+=1
    elif s[0]=="-": c-=1
    elif ":" in s: r+=c*len(s.split(":")[1])
print(r)