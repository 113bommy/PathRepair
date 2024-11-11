n = int(input())

k = [int(x) for x in input().split()]

j = []
wait = []

for i in range(n):
  j.append([int(x) for x in input().split()])
  wait.append(sum(j[i])* 5 + 15)
  
print(min(wait))