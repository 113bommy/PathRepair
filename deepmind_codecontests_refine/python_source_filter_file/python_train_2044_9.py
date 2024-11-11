n=int(input())
a,b=0,0
l=[]
for i in range(n,0,-1):
    if a<=b:
        a+=i
        l.append(i)
    else:
        b+=i
print(a-b)
print(len(l),end='')
print(*tuple(l))
