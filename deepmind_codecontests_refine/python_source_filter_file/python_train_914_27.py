n=int(input())
H=list(map(int,input().split()))
count=1
for i in range(1, n):
  if H[i]>=H[i-1]:
    count+=1
print(count)