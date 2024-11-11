N = int(input())
for i in range(1, N):
  if int(i*1.08) == N:
    print(i)
    quit()

print(':(')