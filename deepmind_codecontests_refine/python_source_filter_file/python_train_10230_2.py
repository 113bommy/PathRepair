n=int(input())
for i in range(n):
    s=input()
    l=len(s)
    d=dict()
    for i in "0123456789":
        d[i]=0
    for i in s:
        d[i]=d[i]+1
    maxi=0
    for i in"0123456789":
        if(d[i]>maxi):
            maxi=d[i]
    maxi1=0       
    for i in "0123456789":
        for j in "012345678":
            if(i==j):
                continue
            count=0
            flag=1
            for k in s:
                if(k==i and flag==1):
                    flag=0
                if(k==j and flag==0):
                    count=count+1
                    flag=1
            if(count*2>=maxi1):
                maxi1=count*2
    print(min(l-maxi,l-maxi1)) 