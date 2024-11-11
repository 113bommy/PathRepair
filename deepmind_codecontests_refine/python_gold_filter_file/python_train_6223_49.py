s=input()
t=input()

mc=0
for i in range(len(s)-len(t)+1):
    c=0
    for j in range(len(t)):
        if s[i+j]==t[j]:
            c+=1
    mc=max(c,mc)
print(len(t)-mc)
