a=list(input())
ans=1
l=len(a)
i=0
while i<l:
    count=1
    j=i+1
    while j<l:
        if a[j]!=a[j-1]: 
            count+=1
            j+=1
        else: break
    if i==0: count1=count
    if j==l: count2=count
    ans=max(ans,count)
    i=j
#print(ans,count1,count2)
if a[0]==a[-1]: print(ans)
else: print(min(l,max(ans,count1+count2)))