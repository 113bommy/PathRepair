a=int(input())
cnt=0
while int(a/2)!=0:
  #  print(a)
    if (a%2)==1:
        cnt=cnt+1
    a=a/2
print(cnt+1)