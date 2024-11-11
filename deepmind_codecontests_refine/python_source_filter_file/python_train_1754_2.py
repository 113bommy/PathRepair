n,a,b,c,d =map(int,input().split())
n -= 1
ans1 = a + c*n+d+c
ans2 = a+d*n+c+d
for i in range(n+1):
  ans1 -= d+c
  ans2 -= c+d
  if (ans1<= b and b<ans2):
    print("YES")
    exit()
print("NO")