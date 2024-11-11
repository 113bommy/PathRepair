n = int(input())
s=n
l=[n]
i=s-1
while(s>0):
    if i==0:
        break
    if s%i==0:
        l.append(i)
        s=i
        i=s-1
        if i==0:
            break
    else:
        i-=1
print(*l)
