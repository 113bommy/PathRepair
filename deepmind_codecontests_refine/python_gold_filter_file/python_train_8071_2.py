mod=pow(10,9)+7
ans=1
d={}
string="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"
for i in range(64):
    for j in range(64):
        if string[i&j] in d:
            d[string[i&j]]+=1
        else:
            d[string[i&j]]=1
s=input()
for i in s:
    ans=(((ans%mod)*(d[i]%mod))%mod)
print(ans)