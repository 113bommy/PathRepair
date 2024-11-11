def check(x):
    temp=[]
    for i in t:
        temp.append(i)
    for i in range(x):
        temp[a[i]-1]=''
    #print(''.join(temp))
    l=0;r=0;c=0
    while r<len(s) and l<len(t):
        if s[r]==temp[l]:
            r+=1;c+=1
        l+=1
    #print(c)
    return c==len(s)
t=input()
s=input()
a=list(map(int,input().split()))
lo=0;hi=len(a)
while lo<hi-1:
    mid=lo+(hi-lo)//2
    #print(lo,hi,mid)
    if check(mid):
        lo=mid
    else:
        hi=mid
    
print(lo)
