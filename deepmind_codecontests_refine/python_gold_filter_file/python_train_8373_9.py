s=list(input().split())
t=list(input().split())
k=0
t1=""
s1=""
for i in s:
    s1=s1+i
for i in t:
    t1=t1+i
s1=list(s1)
t1=list(t1)
for i in t1:
    if i in s1:
        s1.remove(i)
    else:
        k=1
        break
if k==1:
    print("NO")
else:
    print("YES")
