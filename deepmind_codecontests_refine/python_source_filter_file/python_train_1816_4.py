def isPal(a):
    l=len(a)
    for i in range(l//2):
        if a[i]!=a[l-i-1]:
            return 0
    return 1

s=input()
dic={'A':1,'H':1,'I':1,'M':1,'O':1,'T':1,'U':1,'V':1,'W':1,'X':1}
n=len(s)
fl=0
for i in range(n):
    if s[i] not in dic:
        fl=1
        break
if fl==1:
    print("NO")
else:
    if isPal(s):
        print("YES")
    else:
        print("NO")
