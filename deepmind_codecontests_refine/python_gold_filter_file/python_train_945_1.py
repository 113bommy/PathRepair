
def gcd(a,b): 
    if(b==0): 
        return a 
    else: 
        return gcd(b,a%b) 


n=int(input())


sum=0 
l,r=0,0
while n>0:
      
      l,r=input().split()
      l=int(l)
      r=int(r)
      t=gcd(l,r)
      t=int(l*r)//t
      sum=gcd(sum,t)
      n-=1

if sum==1:
    print(-1)
elif gcd(l,sum)==1:
    i=2
    sum=gcd(r,sum)
    while sum>=i*i:
      if sum%i==0:
         sum=i
         break
      i+=1
    print(int(sum))
else :
    i=2
    sum=gcd(l,sum)
    while sum>=i*i:
      if sum%i==0:
         sum=i
         break
      i+=1
    print(int(sum))
    
    
    
    
    