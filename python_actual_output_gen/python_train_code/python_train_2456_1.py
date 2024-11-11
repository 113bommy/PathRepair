n = int(input())
a = list(map(int,input().split()))
a *= 2
acc1 = [0,a[0]]
acc2 = [0,a[1]]
for i in range(1,2*n):
  if i%2 == 0:
    acc1.append(acc1[-1]+a[i])
  else:
    acc2.append(acc2[-1]+a[i])
ans = 0
for i in range(n//2+1,n+1):
  ans = max(ans,acc2[i]-acc2[i-n//2-1],acc1[i]-acc1[i-n//2-1])
print(ans)