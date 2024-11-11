a=list(map(int,input().split()))
a.sort()
if((a[0]+a[3]==a[1]+a[2]) or (a[0]+a[2]==a[1]+a[3]) or (a[2]+a[3]==a[0]+a[1])):
  print("YES")
else:
  print("NO")
