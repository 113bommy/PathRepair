for _ in range(int(input())):
    ans=0
    a,b=map(int,input().split())
    if(a%b==0):
        print(a)
    else:
        print(((a//b)*b)+min((b//2),a%b))
