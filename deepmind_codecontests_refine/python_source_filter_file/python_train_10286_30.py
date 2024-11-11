n=int(input())
p=list(map(int,input().split()))
f=0
for i in range(n):
  if p[i]!=i+1:
    f+=1
print("Yes" if f<=2 else "No")
  