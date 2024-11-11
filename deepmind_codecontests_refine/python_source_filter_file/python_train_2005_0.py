t1=int(input())
for _ in range(t1):
  n=int(input())
  a2=input()
  a=[]
  for i in range(n):
    a.append(a2[i])
  b=input()
  ans=[]
  for i in range(n-1,-1,-1):
    if a[i]!=b[i]:
      temp=[]
      for j in range(i):
        temp.append(a[j])
      temp2=[]
      for j in range(i-1,-1,-1):
        if temp[j]=='0':
          temp2.append('1')
        else:
          temp2.append('0')
      if a[0]!=b[i]:
        ans.append(str(i+1))
        for j in range(i):
          a[j]=temp2[j]
      else:
        ans.append('1')
        ans.append(str(i+1))
        for j in range(i):
          a[j]=temp2[j]
  print(len(ans))
  if len(ans)>0:
    print(' '.join(ans))
      