mod = 1000000007

N = int(input())
a = list(map(int,input().split()))

data = [0]*N
for i in a:
  data[i] += 1

cnt = 0
for i in range(1,len(data)):
  if data[i] == 2:
    cnt += 1
  elif data[i] == 0:
    continue
  else:
      print(0)
      exit()
print(pow(2, cnt))