n=int(input())
H=list(map(int,input().split()))
count=1
for i in range(1, n):
  if H[i]>=max(H[:i]):
    count+=1
print(count)