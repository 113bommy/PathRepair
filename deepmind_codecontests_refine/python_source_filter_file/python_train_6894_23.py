c=int(input())
while(c):
  s1=input()
  li=s1.split(" ")
  if((int(li[0])-int(li[1]))%2==0):
    print("NO")
  else:
    print("YES")
  c=c-1