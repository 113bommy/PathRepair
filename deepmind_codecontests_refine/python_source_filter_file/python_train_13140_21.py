n=int(input())
for x in range(n) :
    l=int(input())
    t=list(map(int,input().split()))
    t.sort(reverse=True)
    print(t)