MOD = 10**9+7
r1,c1,r2,c2 = map(int,input().split())
 
size = 1010000*2
f_list = [1]*(size)
for i in range(1,size):
    f_list[i] = (f_list[i-1]*i)%MOD

def func(r,c):
    return (f_list[r+c]*pow(f_list[r],MOD-2,MOD)*pow(f_list[c],MOD-2,MOD))
 
ans = func(r2+1,c2+1)-1
ans += func(r1,c1)-1
ans -= func(r2+1,c1)-1
ans -= func(r1,c2+1)-1
print(ans%MOD)