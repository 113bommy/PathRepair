from sys import stdin,stdout
t=int(input())
for i2 in range(t):
    n=int(input())
    x=list(map(int,stdin.readline().split()))
    new,mi,count1,count2,ans=[0]*(2*n+2),{},0,0,0
    mi[0]=-1
    for i in range(n):
        if x[i]==1: count1+=1
        else: count2+=1
        if count1==count2:ans=max(ans,i+1)
    count1,count2=0,0
    for i in range(n*2-1,n-1,-1):
        if x[i]==1: count1+=1
        else: count2+=1
        if count1==count2:ans=max(ans,n*2-i)
    count1, count2 = 0, 0
    for i in range(n):
        new[i]=x[n+i]
    for i in range(n,2*n):
        new[i]=x[i-n]
    for i in range(2*n):
        if new[i]==1:
            count1+=1
        else:
            count2+=1
        if count1-count2 not in mi:
            mi[count1-count2]=i
        elif mi[count1-count2]<n and i>=n:
            ans=max(ans,i-mi[count1-count2])
    stdout.write(str(n*2-ans))
    stdout.write("\n")