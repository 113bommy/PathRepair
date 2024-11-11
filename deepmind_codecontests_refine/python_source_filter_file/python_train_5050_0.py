#CF 600C isprav
#q=input()
q='aabbcccdd'

alfavitk=[0]*26
alfavit='abcdefghijklmnopqrstuvwxyz'

for i in range(26):
        alfavitk[i]=q.count(alfavit[i])
    
first=0
last=25
while True:
    while alfavitk[first]%2==0 and first<last:
        first+=1
    while alfavitk[last]%2==0 and first<last:
        last-=1
    
    if first<last:
        alfavitk[first]+=1
        alfavitk[last]-=1
        first+=1
        last-=1
    else:
        break

#print(alfavitk)
#print(first)
#print(last)


if alfavitk[first]%2==1:
    res=alfavit[first]
    alfavitk[first]-=1
    
else:
    res=''

for i in range(25,-1,-1):
    if alfavitk[i]%2==1:
        res=alfavit[i]*()
    res=alfavit[i]*(alfavitk[i]//2)+res+alfavit[i]*(alfavitk[i]//2)
        
    
print(res)