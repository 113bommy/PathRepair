s = str(input())
sn=''
l = len(s)
if l % 2:
    sn = s[0]+sn
    for i in range(1,l//2+1):
        sn = s[-i]+sn
        sn = s[i]+sn
else:
    for i in range(l//2):
        sn = s[-i-1]+sn
        sn = s[i]+sn
print(sn)