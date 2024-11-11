a=int(input())
ls=list(map(int,input().split()))
x=0 
while x<a:
    if ls[x]==0 :
        x=x+1
    else:
        break
su=1
ml=1
if x==a:
    print("-1")
    quit()
while x<a:
    if ls[x]==1:
        su=su*ml
        ml=1
    else:
        ml=ml+1
    x=x+1    
print(su)    