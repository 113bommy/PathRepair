n=input()
s=0
for i in n:
    s+=int(i)
print(['NO','YES'][int(n)%s==0])