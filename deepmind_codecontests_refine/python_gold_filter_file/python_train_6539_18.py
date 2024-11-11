N=int(input())
a=[int(input()) for i in range(N)]
for i in a:
  if i%2==1:
    print("first")
    exit()
print("second")