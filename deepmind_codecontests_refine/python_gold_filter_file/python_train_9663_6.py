s=input()
table=[1]+[0 for _ in range(3)] 
abc='ABC'
mod=10**9+7
for i in range(len(s)):
    if s[i]=='?':
        for j in range(3,0,-1):
            table[j]=(3*table[j]+table[j-1])%mod
        table[0]=3*table[0]%mod
    else:
        for j in range(3):
            if s[i]==abc[j]:
                table[j+1]+=table[j]
#print(table)
print(table[3]%mod)
