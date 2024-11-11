n=int(input())
a=[int(i) for i in input().split()]
iro=[0 for i in range(8)]
tyi=0
for i in range(n):
  if a[i]<3200:
    iro[int(a[i]/400)]=1
  else:
    tyi+=1
print(max(iro.count(1),1),min(iro.count(1)+tyi,8))