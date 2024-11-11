n, k = map(int,input().split())
a = list(map(int,input().split()))
b = [a[i+1]-a[i] for i in range(k-1)]
b.append(n-a[-1]+a[0])
print(k-max(b))