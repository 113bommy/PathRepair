s=input()
t=input()
ls=len(s)
lt=len(t)
a=[0]*(ls-lt+1)

for i in range(ls-lt+1):
    for j in range(lt):
        if s[i+j]!=t[j]:
            a[i]+=1

print(min(a))