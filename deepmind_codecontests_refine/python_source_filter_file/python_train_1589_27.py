t=int(input())
for i in range(t):
    x,y,n=[int(h) for h in input().split()]
    print(n-(n%(x+y)))