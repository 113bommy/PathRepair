s=input()
t=input()
ls=len(s)
lt=len(t)
a=[0]*(ls-lt)

for i in range(ls-lt):
    for j in range(lt):
        if s[i+j]!=t[j]:
            a[i]+=1

print(min(a))