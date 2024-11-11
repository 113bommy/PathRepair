n=int(input())
l=[1,1]
c=0
s=""
for i in range(2,n+100):
    c=l[i-1]+l[i-2]
    l.append(c)
for i in range(1,n+1):
    if i in l:
        s=s+"O"
    else:
        s=s+"o"
print(s)

