n = int(input())
a = list(map(int, input().split()))
b = [1]*n
for i in range(n-1):
    b[i+1] = b[i]+a[i]
mi = min(b)
if len(set(b))==n and max(b)-mi==n-1:
    b = [x-mi+1 for x in b]
    print(b)
else:
    print(-1)