n = int(input())
a = list(input())
b = list(input())
ans=0
for i in range(n//2):
    l1 = [a[i],a[n-i-1]]
    l2 = [b[i],b[n-i-1]]
#    print(set(l1+l2))
    if len(set(l1+l2))==4:
        ans+=2
    elif len(set(l1+l2))==3:
        if l1[0]==l1[1]:
            ans+=2
        elif l1[0]==l2[0] or l1[0]==l2[1]:
            ans+=1
        elif l1[1]==l2[0] or l1[1]==l2[1]:
            ans+=1
        elif l2[0]==l2[1]:
            ans+=2    
    elif len(set(l1+l2))==2:
        aa=l1+l2
        if aa.count(l1[0])!=2:
            ans+=1
#    print(ans)
if n%2:
    if a[n//2]!=b[n//2]:
        ans+=1            
print(ans)            


