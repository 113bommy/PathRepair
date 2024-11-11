def gcd(a,b):
  if a==0:
    return b;
  return gcd(b%a,a);

n=int(input())
arr=list(map(int,input().split()))
arr.sort()
res=abs(arr[1]-arr[0]);
for i in range(1,n-1):
    res=gcd(res,abs(arr[i]-arr[i+1]))
c=0;
for i in range(1,n-1):
    if abs(arr[i]-arr[i+1])>res:
        c+=abs(arr[i]-arr[i+1])/res-1;
print(int(c));
