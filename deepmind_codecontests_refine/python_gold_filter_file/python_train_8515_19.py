N,K = [ int(it) for it in input().split() ]
S = [ int(it) for it in input() ]

li = []

v = 1
c = 0
for it in S:
  if (v != it ):
    li.append(c)
    c=1
  else:
    c+=1
  v = it
li.append(c)
s = 0
lis = [0]*(len(li)+1)
for i in range(len(li)):
  lis[i+1]=lis[i]+li[i]
s = 0
for i in range(N):
  if (i*2>=N):
    continue
  a = min(i*2,len(li))
  b = min(i*2+2*K+1,len(li))

  ds2 = lis[b]-lis[a]
  s = max(s,ds2)
print (s)
