n=int(input())
b=list(map(int,input().split()))
s=0
for i in range(n-3):
  s+=min(b[i],b[i+1])
print(s+b[n-2])