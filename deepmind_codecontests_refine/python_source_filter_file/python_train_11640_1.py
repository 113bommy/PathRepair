n=int(input())
a=list(map(int,input().split()))
mx=0
for i in a:
  mx=max(mx, i)
  if mx-i>1:
    print('No')
    return 0
print('Yes')
