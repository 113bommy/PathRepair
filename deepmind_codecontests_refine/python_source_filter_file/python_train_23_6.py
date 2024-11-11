n,k=map(int,input().split(" "))
both=[]
bob=[]
alice=[]

for i in range(n):
    t,a,b=map(int,input().split(" "))
    if a==1 and b==1:
        both.append(t)
    elif a==1:
        alice.append(t)
    elif b==1:
        bob.append(t)

if len(both)==0:
    both.sort()
if len(alice)==0:
    alice.sort()
    
if len(bob)==0:
    bob.sort()

if len(both)+len(alice)<k or len(both)+len(bob)<k:
    print(-1)
else:
    #print(alice,bob,both)
    i=0
    j=0
    ans=0
    q=0
    w=0
    talice=0
    tbob=0
    while i<len(alice) and j<len(bob) and q<k and w<len(both):
        if alice[i]+bob[j]<=both[w]:
            ans+=alice[i]+bob[j]
            talice+=1
            tbob+=1
            i+=1
            j+=1
        else:
            ans+=both[w]
            talice+=1
            tbob+=1
            w+=1
        q+=1
    z=talice
    if i==len(alice) or j==len(bob):
        
        #print(w+k-z+1)
        ans+=sum(both[w:w+k-z])
    elif w==len(both):
        ans+=sum(alice[i:i+k-z])
        ans+=sum(bob[j:j+k-z])
    
    print(ans)
        
            
            
        