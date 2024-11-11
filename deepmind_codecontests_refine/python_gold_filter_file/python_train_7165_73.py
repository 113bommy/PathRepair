n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
chance = sum(b)-sum(a)
for i in range(n):
    if a[i]<b[i]:
        chance -= (b[i]-a[i]+1)//2

if chance < 0:
    print("No")
else:
    print("Yes")