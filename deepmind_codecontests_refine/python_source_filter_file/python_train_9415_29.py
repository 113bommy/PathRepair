import  math
ll=input().split()
n=int(ll[0])
d=int(ll[1])
lll=input().split()
s=0
#print(n)
for i in range(n):
    s+=int(lll[i])
s+=(n-1)*10
if s>d:
    print("-1")
elif s==d:
    print("(n-1)*2")
else:
    t=math.floor((d-s)/5)
    print(t+(n-1)*2)