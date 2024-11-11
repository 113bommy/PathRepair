n,a,b=map(int,input().split())
text=input()

num=0
f=0
for i in range(n):
  alp=text[i]
  if alp=='a' and num<(a+b):
    print("Yes")
    num+=1
  elif alp=='b' and num<(a+b) and f<=b:
    print("Yes")
    num+=1
    f+=1
  else:
    print("No")