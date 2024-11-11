a,b,c=map(int,input().split(' '))
ans=0           
if a<=b:
    c+=a
    if c<=b:
        print(c)
    else:
        print(2*(b+(c-b)//2))
else:
    c+=b
    if c<=a:
        print(c)
    else:
        print(2*(a+(c-a)//2))
    