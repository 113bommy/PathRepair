n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
f1 = [0]*(n+3)
f2 = [0]*(n+3)
f1[1] = a[0]
f2[1] = b[0]
for i in range(1,n):
    f2[i+1] = max(f2[i],max(f1[i-1]+b[i],f1[i]+b[i]))
    f1[i+1] = max(f1[i],max(f2[i-1]+a[i],f2[i]+a[i]))

print (max(f1[n],f2[n]))