p=input()
v=["A","E","I","O","U","a","e","i","o","u"]
for i in range(len(p)-1,-1,-1):
    if (ord(p[i])>=97 and ord(p[i])<=122) or (ord(p[i])>=65 and ord(p[i])<=90):
        w=i
        break
if p[w] in v:
    print("YES")
else:
    print("NO")