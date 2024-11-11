n =int(input())
p = [int(_) for _ in input().split()]
cnt =0
for i in range(len(p)):
  if  p[i] !=(i+1):
    cnt +=1
print('Yes' if cnt <=2 else 'No')