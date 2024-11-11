q=int(input())
h={4:1,6:1,9:1}
for w in range(q):
    n=int(input())
    if n<8:
        if n not in h:
            print(-1)
        else:
            print(1)
    else:
        c=0
        if n%2!=0:
            n-=9
            c+=1
            if n<4 and n!=0:
                print(-1)
            else:
                c+=n//4
                print(c)
        else:
            c+=n//4
            print(c)