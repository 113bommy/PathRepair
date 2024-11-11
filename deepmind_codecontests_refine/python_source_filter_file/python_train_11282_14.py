s=input()
t=input()
z=len(t)
c=1
for i in range(z):
    if s[i]==t[i]:
        c+=1
    
print(c)