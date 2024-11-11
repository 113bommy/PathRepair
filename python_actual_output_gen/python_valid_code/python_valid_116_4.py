n=int(input())
i=int(sqrt(n))//2
while(i*(i+1)//2<n):
  i+=1
print(i)