ans = N = int(input())
for i in range(N):
  a_,n6,n9 = 0,i,N-i
  while (n6>0): a_ += n6%6; n6 = n6//6
  while (n9>0): a_ += n9%9; n9 = n9//9
  ans = min(ans, a_)
print(ans)
