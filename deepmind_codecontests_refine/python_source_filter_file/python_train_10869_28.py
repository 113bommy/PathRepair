n  =int(input())
solds = list(map(int, input().split()))
mi = 10000000
n1 = n2 = -1
for i in range(1, n):
    if(abs(solds[i]-solds[i-1])<mi):
        n1 = i
        n2 = i-1
        mi = abs(solds[i]-solds[i-1])
if(abs(solds[n-1]-solds[0])<mi):
    n1 = n-1
    n2 = 0

print(n1, n2)