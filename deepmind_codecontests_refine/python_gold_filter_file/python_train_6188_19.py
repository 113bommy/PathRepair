n,a,b=map(int,input().split())
for x in map(int,input().split()):
    print(x - ((x*a//b)*b+a-1)//a)