n=int(input())
for i in range(2,10):
  if n%i==0 and (n//i)<=9:
    print("Yes")
    break
else:
  print("No")