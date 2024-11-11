t=[]
for i in range(int(input())):
    s,a,b=input().split()
    a=int(a)
    b=int(b)
    
    if a>=2400 and b>a:
        t.append(s)
if len(t)>0:
    print("YES")
else:
    print("NO")