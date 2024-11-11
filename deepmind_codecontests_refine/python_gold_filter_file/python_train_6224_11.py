s=input()
s=s[::-1]
n=len(s)
 
count=[0]*2019
count[0]=1
num,d=0,1
 
for i in s:
  num+=int(i)*d
  num%=2019
  d*=10
  d%=2019
  count[num]+=1
 
ans=0
for i in count:
  ans+=i*(i-1)//2
  
print(ans)