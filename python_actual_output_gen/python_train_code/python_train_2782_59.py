n = int(input())
num = 0
for i in range(1,n+1):
  if len(str(n))%2 == 1:
    num += 1
print(num)