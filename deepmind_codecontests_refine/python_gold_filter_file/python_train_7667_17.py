input()
a=list(input().split())
d={}
for s in a:
    b=sorted(set(s))
    d[str(b)]=1
print(len(d))
    
