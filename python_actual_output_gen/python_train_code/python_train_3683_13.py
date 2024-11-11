num=int(input())
lst=list(map(int,input().split()))
one=0
two=0
ans=0
checker=0
if lst[0] == 1:
    one+=1
else:
    two+=2
i=1
while i < len(lst):
    if lst[i]!=lst[i-1]:
        checker+=1
    if checker==2:
        ans=max(ans,min(one,two))
        if lst[i]==1:
            one=0
        else:
            two=0
        checker=1
    if lst[i] == 1:
        one+=1
    else:
        two+=1
    i+=1
ans=max(ans,min(one,two))
print(ans*2)



