import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
  n=int(input())
  ans=[]
  s1=input()
  s2=input()
  s3=input()
  fincount=0
  count10=0
  for i in range(2*n):
    if s1[i]=='0':
      count10+=1
  if count10>=n:
    fincount+=1
  count20=0
  for i in range(2*n):
    if s2[i]=='0':
      count20+=1
  if count20>=n:
    fincount+=1
  count30=0
  for i in range(2*n):
    if s3[i]=='0':
      count30+=1
  if count30>=n:
    fincount+=1
  if fincount>=2:
    mode='0'
    unmode='1'
  else:
    mode='1'
    unmode='0'
  if mode=='0':
    if count10>=n and count20>=n:
      st1=s1
      st2=s2
    elif count10>=n and count30>=n:
      st1=s1
      st2=s3
    elif count20>=n and count30>=n:
      st1=s2
      st2=s3
  else:
    if count10<=n and count20<=n:
      st1=s1
      st2=s2
    elif count10<=n and count30<=n:
      st1=s1
      st2=s3
    elif count20<=n and count30<=n:
      st1=s2
      st2=s3
  pointer1=0
  pointer2=0
  while pointer1<2*n or pointer2<2*n:
    
    while pointer1<2*n and st1[pointer1]==unmode:
      pointer1+=1
      ans.append(unmode)
    while pointer2<2*n and st2[pointer2]==unmode:
      pointer2+=1
      ans.append(unmode)
    if pointer1==2*n and pointer2==2*n:
      break
    ans.append(mode)
    pointer1+=1
    pointer2+=1
  print(''.join(ans))