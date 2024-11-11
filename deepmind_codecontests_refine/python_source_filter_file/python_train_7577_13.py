from math import factorial
iMOD = 10**9 + 7

n = int(input())
s = input()
a = [0] * (n * 2)
for i in range(n*2):
    if s[i] == "B":
        a[i] = 1
        
prevbit = 0
prevlr = 0
lr = [0] * (n*2)
for i in range(n*2):
    if a[i] != prevbit:
        lr[i] = prevlr
    else:
        lr[i] = (prevlr + 1) % 2
    prevlr = lr[i]
    prevbit = a[i]
    
#print(lr)
    
ans = 1
if sum(lr) != n:
    ans = 0
else:
    suml = 0
    for i in range(n*2):
        if lr[i] == 1:
            ans = (ans * suml) % MOD
            suml -= 1
            if suml < 0:
                ans = 0
                break
        else:
            suml += 1
            
print((ans*factorial(n))%MOD)