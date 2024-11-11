def fact(n):
    product=1
    for i in range(1,n+1):
        product= product*i
    return product
def C(n,r):
    return int(fact(n)/(fact(r)*fact(n-r)))
    
    
seq= input()
 
A= seq.split()
 
boys= int(A[0])
gals= int(A[1])
team= int(A[2])
 
boy_min= max(team-gals,4)
gal_min= max(team-boys,1)
 
ans=0
 
while boy_min<=gal_min:
    ans+= C(boys,boy_min)*C(gals,team-boy_min)
    boy_min+=1
    
print(ans)