a,b,c=map(int,input().split())
x,y,z=map(int,input().split())
sparea=0 
spareb=0 
sparec=0 
reqa=0 
reqb= 0 
reqc = 0 
if x<=a:
    sparea=(a-x)
else:
    reqa=(x-a)
if y<b:
    spareb=(b-y)
else:
    reqb=(y-b)
if z<c:
    spare=(c-z)
else:
    reqc=(z-c)
#print(reqa,reqb,reqc)
#print(sparea,spareb,sparec)
if reqa>0 and reqb>0 and reqc>0:
    print('No')
    exit() 
if reqa>0 and reqb>0:
    if sparec>=2*reqa+2*reqb:
        print('Yes')
    else:
        print('No')
    exit() 
if reqa>0 and reqc>0:
    if spareb>=2*reqa+2*reqc:
        print('Yes')
    else:
        print('No')
    exit() 
if reqb>0 and reqc>0:
    if sparea>=2*reqb+2*reqc:
        print('Yes')
    else:
        print('No')
    exit() 
if reqa>0:
    if spareb//2+sparec//2>=reqa :
        print('Yes')
    else:
        print('No')
    exit() 
if reqb>0:
    if sparea//2+sparec//2>=reqb:
        print('Yes')
    else:
        print('No')
    exit() 
if reqc>0:
    if sparea//2+spareb//2>=reqc:
        print('Yes')
    else:
        print('No')
    exit()
print('Yes')