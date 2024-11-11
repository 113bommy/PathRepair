h,w,k=map(int,input().split())
ans="No"
for i in range(h+1):
  for j in range(w+1):
    if i*j+(h-i)*(w-j) == k:
      ans="Yes"
print(ans)