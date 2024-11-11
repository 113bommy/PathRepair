n,h=int(input()),list(map(int,input().split()));m,a=0,0
for i in range(n):
  if m<=h[i]:
    a+=1
    m=h[i]
print(a)