s=list(input())
t=list(input())
x=len(s)
y=len(t)
for i in range(x-y):
    for j in range(y):
        if s[x-y-i+j]!=t[j] and s[x-y-i+j]!="?":
            break
    else: 
        s[x-y-i:x-i]=t
        print("".join(s).replace("?","a"))
        exit()
print("UNRESTORABLE")        