A,B = map(int,input().split(' '))
num = 0
for str(x) in range(A,B+1):
  if str(x) == str(x)[::-1]:
    num += 1
print(num)