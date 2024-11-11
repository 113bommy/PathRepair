ret=0
m=10
for _ in range(5):
  y=int(input())
  ret+=(y+9)//10
  if y%10!=0:
    m=min(m,y%10)
print(ret-(10-m))
