a,n=0,int(input())
for i in range(2,10**6):
  x=j=0
  while n%i<1:n/=i;x+=1
  while x>=j:a+=1;j+=1;x-=j
print(a+(n>1))