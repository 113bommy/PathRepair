t=int(input())
for case in range(t):
    s,a,b,c=list(map(int,input().split()))
    print((s//c)+(s//a)*b)