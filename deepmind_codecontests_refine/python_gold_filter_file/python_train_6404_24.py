n=input()
m=input()
s=""
for i in range(len(n)):
    if n[i]==m[i]:
        s=s+"0"
    else:
        s=s+"1"
print(s)