for _ in[0]*int(input()):
  input()
  a=''.join(filter(lambda x:int(x)%2,input()))
  x=len(a)
  print([[a[1:],a][x%2],-1][x<1])
