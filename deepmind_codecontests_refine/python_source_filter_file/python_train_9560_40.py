A,B = map(int,input().split(' '))
num = 0
for x in range(A,B+1):
  if str(x)[:2] == str(x)[3:5]:
    num += 1
print(num)