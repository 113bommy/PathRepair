n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

x = y = 0
for i in range(n):
    dif = b[i]-a[i]
    if dif>0:x += dif//2
    else:y += -dif

print('Yes' if x>=y else 'No')