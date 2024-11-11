c=int(input())
while(c):
  s1=input()
  li=s1.split(" ")
  if((int(li[0])%int(li[1]))==0):
    print("YES")
  else:
    print("NO")
  c=c-1