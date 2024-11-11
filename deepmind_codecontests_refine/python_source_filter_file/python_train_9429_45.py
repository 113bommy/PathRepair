n=int(input())
a=sorted(map(int,input().split()))
for i in range(n-2):
 if a[i]+a[i+1]>=a[i+2]:print("YES");exit()
print("NO")