h,w,k=map(int,input().split())
ans="No"
for i in xrange(h):
  for j in xrange(w):
    if i*j+(h-i)*(w-j) == k:
      ans="Yes"
print(ans)