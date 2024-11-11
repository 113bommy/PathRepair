t=int(input())
for _ in range(t):
  st=input()
  cnt=0 
  for s in st:
    if s=='N':
      cnt+=1 
    
  if cnt<=1:
    print("YES")
  else:
    print("NO")