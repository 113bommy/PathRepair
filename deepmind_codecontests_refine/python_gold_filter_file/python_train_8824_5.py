a=int(input())
ans=0
for i in range(1,a+1):
  num=a//i
  ans+=(((num+1)*num)//2)*i
print(ans)