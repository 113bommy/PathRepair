
a = int(input())
b = input()
mid = a//2
f = mid
s = mid
while (f>0 and b[f]=='0'):
    f = f - 1
while (s<a-1 and b[s]=='0'):
    s = s + 1

ans = 1e18
for number in [-1, 0, 1]:
    keysA = f+number
    keysB = s+number
    fa = 0
    fb = 0
    sa = 0
    sb = 0
    if(len(b[:keysA]) > 0) :
        fa = int(b[:keysA])
    if(len(b[keysA:]) > 0) :
        fb = int(b[keysA:])
    if(len(b[:keysB]) > 0) :
        sa = int(b[:keysB])
    if(len(b[keysB:]) > 0) :
        sb = int(b[keysB:])
    if(keysA >= 0 and keysA <= a-1 and b[keysA]!='0'):
        ans = min(ans, fa+fb)
    if(keysB >= 0 and keysB <= a-1 and b[keysB]!='0'):
        ans = min(ans, sa+sb)
    
print(ans)