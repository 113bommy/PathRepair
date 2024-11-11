n=int(input())
a=list(map(int,input().split()))
a.sort()
for i in range(n-2):
    if a[i+2]<a[i+1]+a[i]:
        print("YES")
        exit(0)
print("NO")
