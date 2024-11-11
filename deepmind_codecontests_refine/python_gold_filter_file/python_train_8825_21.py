A,B = map(int,input().split())
for i in range(0,1001):
  if int(i*0.08) == A and int(i*0.1)==B:
    print(i)
    exit()

print(-1)