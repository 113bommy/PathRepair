n = int(input())

for i in range(1,n):
  txd = int(i*1.08)
  if n==txd:
    print(i)
    exit()
print(":(")