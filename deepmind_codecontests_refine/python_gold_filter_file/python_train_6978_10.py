n = int(input())
person = [[0 for _ in range(10)] for _ in range(12)]

for _ in range(n):
  b, f, r, v = [int(m) for m in input().split()]
  person[3*(b-1)+f-1][r-1] += v

for index, p in enumerate(person):
  print(" "+" ".join([str(m) for m in p]))
  if (index+1)%3 == 0 and index < len(person)-1:
    print("####################")