n=int(input())
sums=0
digits=0
for _ in range(n):
  a,b=map(int,input().split())
  sums+=a*b
  digits+=b
ans=(digits-1)+(sums+9-1)//9
print(ans)