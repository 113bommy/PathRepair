a=list(input())
def pro(a):
    m=1
    c=0
    for i in range(len(a)):
        if int(a[i])==0 and c==0:
            m=1
        elif int(a[i])!=0:
            c=1
            m=m*int(a[i])
        else:
            m=0
    return m
ma=0
b=['9' for i in range(len(a))]
for i in range(len(a)):
    if a[i]=='0':
        pass
    else:
        b[i]=chr(ord(a[i])-1)
        ma=max(ma,pro(b))
        b[i]=a[i]
print(ma)
            
