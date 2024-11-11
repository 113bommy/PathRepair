mod = 998244353

n = int(input())
s = input()

ans = 1
R,G,B,RG,GB,BR = 0,0,0,0,0,0

if s[0] == 'R':
    R = 1
elif s[0] == 'G':
    G = 1
else:
    B = 1

for i in range(1,3*n):
    if s[i] == 'R':
        if GB > 0:
            ans = (ans * GB) % mod
            GB -= 1
        elif G > 0:
            ans = (ans * G) % mod
            G -= 1
            RG += 1
        elif B > 0:
            ans = (ans * B) % mod
            B -= 1
            BR += 1
        else:
            R += 1
    elif s[i] == 'G':
        if BR > 0:
            ans = (ans * BR) % mod
            BR -= 1
        elif R > 0:
            ans = (ans * R) % mod
            R -= 1
            RG += 1
        elif B > 0:
            ans = (ans * B) % mod
            B -= 1
            GB += 1
        else:
            G += 1
    else:
        if RG > 0:
            ans = (ans * RG) % mod
            RG -= 1
        elif R > 0:
            ans = (ans * R) % mod
            R -= 1
            BR += 1
        elif G > 0:
            ans = (ans * G) % mod
            G -= 1
            GB += 1
        else:
            B += 1
        
for i in range(n):
    ans = (ans * (i+1)) % mod

print(ans)