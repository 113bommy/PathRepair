n=int(input())
i=0
while i*(i+1)//2<n:
  i+=1
no=i*(i+1)//2-n
for j in range(1,i+1):
  if j!=no:
    print(j)
