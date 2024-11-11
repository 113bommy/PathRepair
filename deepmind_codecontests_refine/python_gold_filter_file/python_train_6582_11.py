from math import factorial
def nCk(k,n):
    num = factorial(n)
    k_f = factorial(k)
    return ((num)//(k_f*(factorial(n-k))))

boys,girls,need = map(int,input().split())
ans = 0
for i in range(4,boys+1):
    if need-i<1 or need-i>girls or i>boys:
        continue
    ans+= nCk(i,boys)*nCk(need-i,girls)
print(ans)
