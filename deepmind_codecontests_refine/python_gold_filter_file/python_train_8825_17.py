A,B = map(int,input().split())
for i in range(10001):
  if i*0.08//1 == A and i*0.1//1 == B:
    print(i)
    exit()
print(-1)