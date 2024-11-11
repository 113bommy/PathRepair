a = input()
x = sorted(list(map(int,input().split())))
cnt=0
for i in range(a-1):
  cnt += x[2*i]
print(cnt)
