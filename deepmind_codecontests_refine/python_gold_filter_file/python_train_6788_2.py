import math
def solution(n):
    var1 = 998244353
    var3 = n
    var2 = 0
    i=n
    while(i>1):
        var2 = (var2 + var3 * (i - 1) * (n - i + 1) - var3) % var1
        var3 = var3 * i % var1
        i-=1
    var2 = (var3 * (var3 - n + 2) - 2 * var2) % var1
    if var2 & 1: var2 += var1
    return var2 // 2
 
 
x = int(input())
ans = solution(x)
print(ans)