n=int(input())

a = [0]*n
b = [0]*n
 
for i in range(n):
    a[i], b[i] = map(int, input().split())

a.sort()
b.sort()

youso = int(n/2)

if n % 2 != 0:
    print(b[youso]-a[youso]+1)
else:
    print((b[youso]+b[youso-1])-(a[youso]+a[youso-1])+1)