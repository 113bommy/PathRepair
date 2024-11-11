A, B = map(int, input().split())
for i in range(1, 100):
  if int(i*1.08) == A and int(i*1.1) == B:
    print(i)
    exit()
print(-1)