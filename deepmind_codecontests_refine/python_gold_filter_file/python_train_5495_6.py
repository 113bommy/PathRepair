K, N = map(int,input().split())
a = list(map(int,input().split()))
x = [a[0]-a[-1]+K]
for i in range(1,N):
    x.append(a[i]-a[i-1])
print(K-max(x))