t = int(input())
while(t):
    s,a,b,c = map(int,input().split())
    a1 = (c//a) - ((b-1)//a)
    a2 = s//a
    print(a1,a2)
    print(a2-a1)
    t-=1