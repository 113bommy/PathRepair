a,t = map(int,input().split())
s = t
ctr = 0
for i in range(a):
    k,r = input().split()
    if k == "+":
        s+=int(r)
    elif k == "-" and s-int(r) > 0:
        s-=int(r)
    elif k =="-" and s-int(r) < 0:
        ctr+=1
print(s,ctr,end=" ")
