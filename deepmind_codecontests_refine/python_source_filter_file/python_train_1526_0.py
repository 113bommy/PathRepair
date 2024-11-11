a,b,c=map(int,input().split())
z=[*range(1,a+1)]
b,c=sorted([b,c])
s=0;k=a
while 1:
    p=[]
    for i in range(0,k,2):
        if z[i]==b and z[i+1]==c:
            s+=1
            if len(z)==2:print("Final!!")
            else:print(s)
            exit()
        elif z[i]==b:p+=[z[i]]
        elif z[i+1]==b:p+=[z[i+1]]
        elif z[i] == c:p += [z[i]]
        elif z[i + 1] == c:p += [z[i + 1]]
        else:p+=[z[i]]
    k//=2;z=p;s+=1

