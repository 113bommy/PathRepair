n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))


bsup = 0
asup = 0
for i in range(n):
    if b[i] > a[i]:
        bsup += b[i]-a[i]
    else:
        asup += a[i]-b[i]

if bsup//2 >= asup:
    print("Yes")
else:
    print("No")