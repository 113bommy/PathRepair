n = int(input())
for i in range(1, n//4 + 1):
  if (n - i*4) % 7 == 0:
    print("Yes")
    exit()
print("No")