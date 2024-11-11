n =int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
dp = [0] * (n//2+1)
dp2 =  [0] * (n//2+1)
fi = 0
se = 0
for i in range(n):
  fi +=a[i] * i
  fi +=b[-i-1] * (i+n)
dp[0] = fi
for i in range(n):
  if i != 0:
    se +=a[-i] * (i+n)
  se +=b[i] * (i+1)
dp2[0] = se
gou = sum(a)+ sum(b) -a[0]
gou2 = gou + 0
for i in range(1,n//2+1):
  gou -= (b[i*2-2] +b[i*2-1])
  dp[i] = dp[i-1] -b[i*2-2] * (2*n-4*(i-1)-2) - b[i*2-1] * (2*n-4*(i-1)-4) + gou*2
  if i == n//2:
    break
  gou -= (a[2*i]+a[2*i-1] )
for i in range(1,n//2+1):
  try:
    gou2 -= (a[2*i] + a[2*i-1]+ b[2*i-2] + b[2*i-1])
  except:
    break
  dp2[i] = dp2[i-1] -a[i*2-2] * (2*n-4*(i-1)-2) - a[i*2-1] * (2*n-4*(i-1)-4) + gou2*2
dp.extend(dp2)
print(max(dp))