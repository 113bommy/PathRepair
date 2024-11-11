N = int(input())
for x in range(9,0,-1):
  if N % x == 0 and N // x < 10:
    print("yes")
    exit()
print("no")