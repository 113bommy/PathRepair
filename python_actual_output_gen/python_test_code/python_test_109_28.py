n = int(input())
a = list(map(int, input().split()))

an = 1

for x in a:
  an *= x
  if (an > 10**18):
    print(-1)
    exit(0)

print(an)