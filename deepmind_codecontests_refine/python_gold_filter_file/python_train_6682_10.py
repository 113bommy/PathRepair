a,b=map(int,input().strip().split())
L=[0,4,7]
def generateLuckyNumbers(L,a):
  if a <= 1000000001:
        x = a*10+4
        y = a*10+7
        L.append(x)
        L.append(y)
  return L 

  
def calcul(k,l,e,d):
  
  
    return(min(l-k,e-k,l-d+1,e-d+1))
  

i=1
while i<len(L):
  L=generateLuckyNumbers(L,L[i])
  i=i+1

j=0
while j<len(L) and a>L[j]:
  j=j+1
count=0 
if b<=4:
  count=count+(1+calcul(a,4,b,a))*4
else:
  while j+1<len(L) and L[j-1]<=b:
    
    count=count+calcul(L[j-1],L[j],b,a)*L[j] 
  
      
    j=j+1 
print(count)
  



  
