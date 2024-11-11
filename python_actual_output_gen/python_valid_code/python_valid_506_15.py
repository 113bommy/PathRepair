T=int(input())
for i in range(T):
    n=int(input())
    c=n//3
    if n%3==0:
        print(c,c)
        continue
    else:
        if c*2 + (c-1)*1 ==n:
            print(c-1,c)
        else:
            print(c,c+1)
    