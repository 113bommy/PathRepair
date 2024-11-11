n=int(input())
s=[]
f=0
for i in range(n):
    s.append(input())
for i in range(n):
    if("OO" in s[i]):
        s[i]=s[i].replace("OO","++")
        f=1
        break
if f:
    print("YES")
    for i in range(n): print(s[i])
else:
    print("NO")