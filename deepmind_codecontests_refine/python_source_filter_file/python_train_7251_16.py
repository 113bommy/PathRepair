n,s=(int(i) for i in input().split())
times=[0]
for i in range(n):
  h,m=(int(j) for j in input().split())
  time=h*60+m
  times.append(time)
requiredTime=-1

if times[1]>s+1:
  requiredTime=times[0]
else:
  for i in range(1, n):
    if times[i+1]-times[i]>=s+s+2:
      # 1 - длительность посадки, s - пауза перед взлетом
      requiredTime=times[i]+1+s
      break
    
if requiredTime==-1:
  requiredTime=times[n]+1+s
  
h=requiredTime//60
m=requiredTime%60
print(h,m)