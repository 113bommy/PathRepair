a,b = map(int,input().split())
s = b
ctr = 0
for i in range(a):
    k,t = input().split()
    if k == "+":
        s+=int(t)
    elif k == "-" and s-int(t) > 0:
        s-=int(t)
    elif k =="-" and s-int(t) < 0:
        ctr+=1
print(s,ctr,end=" ")
