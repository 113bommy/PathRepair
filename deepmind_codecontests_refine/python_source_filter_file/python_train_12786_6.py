n=int(input())
while True:
  if n%4==0:
    print("YES")
    break
  n-=7
  if n<0:
    print("NO")
    break