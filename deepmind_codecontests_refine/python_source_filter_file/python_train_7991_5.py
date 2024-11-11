n,k=map(int,input().split())
a=list(map(int,input().split()))

ll=0
rr=10**9+1
for _ in range(10**3):
  #最も長い丸太がこれになる
  ans=(ll+rr)/2.0
  cnt=0
  for item in a:
    if item>ans:
	    cnt+=((-1*item)//ans)*(-1)-1
  if cnt<=k:
    rr=ans
  else:
    ll=ans
print(int((-1*ans//1)*(-1)))