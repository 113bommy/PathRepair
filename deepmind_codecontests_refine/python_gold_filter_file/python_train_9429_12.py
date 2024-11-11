# cook your dish here
n=int(input())
a=list(map(int,input().split(' ')))
a=sorted(a)

check=0
for i in range(n-2):
  if ((a[i]+a[i+1])>a[i+2]) and ((a[i+2]+a[i+1])>a[i]) and ((a[i]+a[i+2])>a[i+1]):
    check=1
    break
print("YES"if check is 1 else "NO")
