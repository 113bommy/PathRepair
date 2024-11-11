n = int(input())
p = list(map(int,input().split()))

MIN = 10*10
cnt =0
for i in p:
  if MIN>i:
    MIN = i
    cnt +=1
print(cnt)