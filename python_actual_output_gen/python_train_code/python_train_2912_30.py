
n=int(input())

while (n<9000):
  n+=1
  ss=set(str(n))
  if(len(ss)==4):
    print(n)
    break