n = int(input())
j = [int(j) for j in input().split()]
k = 0
num_0 = j.count(0)
num_1 = j.count(1)
max = 0
for i in range(n):
  for w in range(n-1):
    z = j[i:w+1]
    a = z.count(1)
    b = z.count(0)
    num = num_1 + b - a
    if num > max: max = num 
print(max)