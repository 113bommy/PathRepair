n = int(input())
a = [int(x) for x in input().split()]
otv = 1
for x in a:
  otv *= x
  if otv > 10**18:
    print(-1)
    exit(0)
print(otv)