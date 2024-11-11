mod = 1000000007

def fast(x, wyk) :
    if(wyk == 0) : 
        return 1
    hf = fast(x, int(wyk / 2))
    hf = (hf * hf) % mod
    if(wyk % 2 == 1):
        hf = (hf * x) % mod
    return hf

I = input().split()
x = int(I[0])
k = int(I[1])

res = x * fast(2, k + 1) - fast(2, k) + 1
res %= mod

if (x == 0) : 
    res = 0

print (res)
