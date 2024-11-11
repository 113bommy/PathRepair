n=int(input())
i,x,l=1,1,[1]
if n==2:
    print(1)
    print(2)
    exit()
while x <n:
    i+=1
    x+=i
    if x<=n:
        l.append(i)
    else:
        l[-1]=n-sum(l[:-1])
        break

print(len(l))
print(*l)
