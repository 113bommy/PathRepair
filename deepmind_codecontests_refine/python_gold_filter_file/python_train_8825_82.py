A,B = map(int,input().split())
for x in range(1,10001):
  if (0.1*x)//1 == B and (0.08*x)//1 == A:
    print(x)
    exit(0)
print(-1)