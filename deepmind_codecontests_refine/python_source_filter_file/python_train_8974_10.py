t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=[int(x) for x in input().split()]
    diff=a.count(1)-a.count(2)
    ax=a[:n]
    b=a[n:]
    ax.reverse()
    a=ax
    s1={}
    s2={}
    mini=9898598989
    count=0
    if diff==0:
        print(0)
        continue
    for i in range(n):
        if b[i]==1:
            count+=1
            if count not in s1:
                s1[count]=i+1
            if count==diff:
                mini=min(mini,i+1)
        else:
            count-=1
            if count not in s1:
                s1[count]=i+1
            if count==diff:
                mini=min(mini,i+1)
        #print("Mini=",mini,count)        
    count=0   
    s1[diff]=0
    #print(s1)
    for i in range(n):
        if a[i]==1:
            count+=1
            if -(count-diff) in s1:
                mini=min(mini,i+s1[-count+diff]+1)
        else:
            count-=1
            if -(count-diff) in s1:
                mini=min(mini,i+s1[-count+diff]+1)
        #print(count)        
    print(mini)            
                