N = int(input())

for i in range(0,50001):
    if int(i*1.08)==N:
      print(N)
      exit()
print(":(")