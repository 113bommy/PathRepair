N = int(input())
r = 55555

mp = [1]*(r+1)
i = 2

while 2*i <= r:
  j = 2
  while i*j <= r:
    mp[i*j] = 0
    j += 1
  i += 1
  
k = 0
l = 1
rlt = []
while k < N:
  if mp[30*l-1] == 1:
    rlt.append(30*l-1)
    k += 1
  l += 1

print(' '.join(map(str,rlt)))
