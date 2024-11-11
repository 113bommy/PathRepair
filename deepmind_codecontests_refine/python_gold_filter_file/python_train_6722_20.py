import math
n=int(input())
k=int(math.sqrt(n))
ans=[]
for i in range(1,k+1):
     if n%i==0:
          ans.append(i)
print(min(max(ans),n//max(ans)),max(max(ans),n//max(ans)))
     

               
                    

                    
