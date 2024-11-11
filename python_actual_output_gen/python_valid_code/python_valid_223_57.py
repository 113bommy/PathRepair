N = int(input())
for n4 in range(N//4+1):
  if (N-n4)%7 == 0:
    print("Yes")
    exit()
print("No")