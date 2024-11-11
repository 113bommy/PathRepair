s=input()
t=input()
a=dict()
res=1
for i in range(ord('z')-ord('a')+1):
	a[chr(ord('a')+i)]=0
a['a']=a['e']=a['u']=a['i']=a['o']=a['y']=1

if len(s)!=len(t):
    print("No")
else:
    for i in range(len(t)):
        if a[s[i]]!=a[t[i]]:
            res=0
            break
    if res==1:
        print("Yes")
    else:
        print("No")
