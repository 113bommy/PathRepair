a = int(input())
num = 0
for i in range(a):
  if len(str(i+1))%2 == 1:
    num +=1
print(num)
