n=input()
m=input()
s=""
for i in range(len(n)):
    if n[i]==m[i]:
        s=s+n[i]
    else:
        s=s+"1"
print(s)