s=input()
t=input()
u=len(t)
for i in (len(s)-u,-1,-1):
    for j in range(u):
        if s[i+j]!="?" and s[i+j]!=t[j]:
            break
    else:
        print(((s[:i]+t)+s[u+i:]).replace("?","a"))
        break
else:
    print("UNRESTORABLE")