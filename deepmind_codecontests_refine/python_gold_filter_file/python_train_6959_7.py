N = int(input())
x = int(N**.5)
while N%x:
  x-=1

print(len(str(N//x)))