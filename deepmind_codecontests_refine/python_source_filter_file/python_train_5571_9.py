n=int(input())
x=list(map(int,input().split()))
maxi,mini=5,5
a,b=0,0
c=1
m=0
for i in range(1,n):
    if maxi==mini:
        if abs(maxi-x[i])==1:
            c+=1
            if x[i]>maxi:
                a=i
                b=-1
            else:
                b=i
                a=-1
            mini=min(mini,x[i])
            maxi=max(maxi,x[i])
        elif abs(maxi-x[i])==0:
            c+=1
        else:
            c+=1
            maxi=mini=x[i]
            a=b=i
    elif x[i]==maxi:
        c+=1
        if a==-1:
            a=i
        b=-1
    elif x[i]==mini:
        c+=1
        if b==-1:
            b=i
        a=-1
    else:
        if x[i]==mini-1:
            if b==-1:
                c=1
                maxi=mini=x[i]
            else:
                c=i-b+1
                maxi=mini
                mini=x[i]
                a=-1
                b=i
        elif x[i]==maxi+1:
            if a==-1:
                c=1
                maxi=mini=x[i]
            else:
                c=i-a+1
                mini=maxi
                maxi=x[i]
                b=-1
                a=i
    m=max(m,c)
print(m)