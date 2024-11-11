for i in range(int(input())):
  n=int(input())
  l=list(map(int,input().split()))
  w=list(sorted(set(l)))
  a=[]
  c=0
  d=0
  y=int(w[0]*w[-1])
  for i in w:
      if(y//i in w):
          k=l.count(i)
          t=l.count(int(y/i))
          if(k==t and k%2==0):
              c=c+1
  if(c==len(w)):
      print('YES')
  else:
      print('NO')