a, b = list(map(int, input().split()))
x = input()
y = input()


pow = [0] * a
sum = [0] * a

for i in range(a):
    index = a - i - 1
    if i == 0:
        pow[i] = 1
        sum[index] = pow[i] * (ord(x[i]) - ord('0'))
    else :
        pow[i] = (pow[i - 1] * 2) % 998244353
        sum[index] = (sum[index + 1] + pow[i] * (ord(x[i]) - ord('0'))) % 998244353

ans = 0
for i in range(b):
    if a == b:
        ans = (ans + sum[i] * (ord(y[i]) - ord('0'))) % 998244353
    if a < b:
        if i < b - a:
            ans = (ans + sum[0] * (ord(y[i]) - ord('0'))) % 998244353
        else:
            ans = (ans + sum[i - b + a] * (ord(y[i]) - ord('0'))) % 998244353
    if a > b:
        ans = (ans + sum[i + a - b] * (ord(y[i]) - ord('0'))) % 998244353
    
print(ans)
    
    