list1=[int(x) for x in input().split()]
x=sum(list1)
if x%5==0:
      print(int(x/5))
else:
      print(-1)