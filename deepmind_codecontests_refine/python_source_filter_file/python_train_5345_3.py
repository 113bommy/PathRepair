a=input()
s=input()
c=0
l=0
if len(a)!=len(s):
    print('NO')
else:
    for i in range(len(a)):
        if a[i]!=s[i]:
            c+=1
            if c==1:
                a1=a[i]
                s1=s[i]
            if c==2:
                if a[i]!=s1 or s[i]!=a1:
                    print('No')
                    c=3
                    l=1
                    
                    break
    if c==2 or c==0 :
        print('YES')         
    elif l==0:
        print('NO')
        