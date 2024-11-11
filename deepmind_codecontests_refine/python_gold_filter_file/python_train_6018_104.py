MOD = 10**9+7
S=input()
dp_old=[0]*13
dp_new=[0]*13
dp_old[0]=1
for c in S:
    if c == '?':
        for i in range(10):
            for j in range(13):
                dp_new[(j*10+i)%13]+=dp_old[j]
    else:
        for i in range(13):
            dp_new[(i*10+int(c))%13]+=dp_old[i]
    dp_old = [i%MOD for i in dp_new]
    dp_new = [0]*13
print(dp_old[5])
