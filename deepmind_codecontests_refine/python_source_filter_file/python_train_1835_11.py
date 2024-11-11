
n = int(input())
s = input()

res = 0

for l in range(n,1,-1):
    for offset in range(0,n-l+1):
        
        chars = set()
        ok = True
        for i in range(offset+1,offset+l):
            if not s[i].islower():
                ok = False
                break
            chars.add(s[i])
        
        if ok:
            res = max(res, len(chars))
print(res)