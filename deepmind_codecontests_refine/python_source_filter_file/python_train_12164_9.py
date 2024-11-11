N=int(input())
T=[0]+[int(x) for x in str(input()).split()]+[0]
V=[0]+[int(x) for x in str(input()).split()]+[0]

time=0
t=[0]
for i in T:
  time+=i
  t.append(time)
ans=0

for j in range(0,2*time):
  m1=1000000000
  m2=1000000000
  t1=j/2
  t2=(j+1)/2
  for i in range(N+2):
    if t1<=t[i]:
      m1=min(m1,V[i]+(t[i]-t1))
    elif t1<=t[i+1]:
      m1=min(m1,V[i])
    else:
      m1=min(m1,V[i]+t1-t[i+1])

    if t2<=t[i]:
      m2=min(m2,V[i]+(t[i]-t2))
    elif t2<=t[i+1]:
      m2=min(m2,V[i])
    else:
      m2=min(m2,V[i]+t2-t[i+1])
    
  #print(1,m1,m2)
  ans+=0.25*(m1+m2)
print(ans)



