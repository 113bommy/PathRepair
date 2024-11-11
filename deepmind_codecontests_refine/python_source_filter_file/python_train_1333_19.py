a=[int(input()) for i in range(5)]
minn,summ=10,0
for i in a:
  minn=min(minn,(i-1)%10)
  summ+=(i+9)//10
print(summ*10+minn+1)