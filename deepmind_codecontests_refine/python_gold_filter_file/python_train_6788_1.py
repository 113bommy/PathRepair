n = int(input())
m = 998244353
p,p_,mul = 1,0,n
def getp():
    global p,p_,mul
    p_ = p
    p = (p*mul)%m
    mul -= 1
    return (p-p_+m)%m
ans = 1+sum([i*getp() for i in range(1,n)])
print(ans%m)