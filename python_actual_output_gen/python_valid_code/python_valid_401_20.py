I=lambda:map(int,input().split())
s,n=I()
p=[]
for i in range(n):
    a,b=I()
    p.append((a,b))
f=1
for a,b in sorted(p,key=lambda x:x[0]):
    if s>=a:
        s+=b
    else:
        f=0
        break
print("YES" if f else "NO")
