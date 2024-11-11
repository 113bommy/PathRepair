def gcd(x,y):
  if x == 0:
    return y
  elif y == 0:
    return x
  if x > y:
    return gcd(x%y,y)
  elif x < y:
    return gcd(x,y%x)
  else:
    return x
n,k=map(int,input().split())
arr=list(map(int,input().split()))
flag1=0
ans1=arr[0]%k
i=1
while(i<n):
    ans1=gcd(arr[i]%k,ans1)
    i+=1
arr1=[0]
ans=ans1
if(ans==0):
    print(1)
    print(0)
else:
    while(ans1<k):
        arr1.append(ans1)
        ans1+=ans
    print(len(arr1))
    print(*arr1)