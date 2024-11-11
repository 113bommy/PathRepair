a, b, c = map(int, input().split())
a = a%b
cnt = 1
while(cnt < 10**5):
  a *= 10
  if a//b == c: 
    print(cnt)
    exit()
  a %= b
  cnt += 1
print(-1)
