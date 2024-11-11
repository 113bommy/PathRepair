n=int(input())
for i in range(n):
    a = int(input())
    if a==9 or a==11:
        print(-1)
        continue
    s = a%4
    k = a//4
    if s==0:
        pass
    elif s==1:
        k -= 1
    elif s==2:
        pass
    else:
        k-=1
    if k ==0:
        print(-1)
    else:
        print(k)
