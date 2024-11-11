nn=int(input())
for ffkfkd in range(nn):
    inp=input().split()
    a=int(inp[0])
    b=int(inp[1])

    n=0
    while a!=b and a!=0 and b!=0:
        if a>b:
            n+=a//b
            a=a%b
        else:
            n+=b//a
            b=b%a
    print(n)