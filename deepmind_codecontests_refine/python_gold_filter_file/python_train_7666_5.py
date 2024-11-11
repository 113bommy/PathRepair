s=input()
p=''
k='abcdefghijklmnopqrstuvwxyzz'
check=False
i=0
for c in s:
    p=(p+k[i]) if c<=k[i] and i<26 else p+c
    i=i+1 if c<=k[i] and i<26 else i
    check=True if i==26 else False
print(p if check else -1)