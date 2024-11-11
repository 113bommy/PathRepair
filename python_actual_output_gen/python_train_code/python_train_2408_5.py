N = int(input())
x = int(n**.5)
while n%x:
  x-=1

print(len(str(n//x)))