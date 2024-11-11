s=input()
t=input()
sl=len(list(s))
tl=len(list(t))
for i in range(sl-tl+1):
    c=0
    for j in range(tl):
        if s[i+j]==t[j] or s[i+j]=='?':c+=1
        else:break
    if c==tl:
        print((s[:i]+t+s[i+tl:]).replace("?", "a"))
        exit()
print('UNRESTORABLE')