n=int(input())
for i in range(n):
    r=input()
    n=list(r)
    n.sort()
    nn="".join(n)
    if nn[::-1]==r:
        print(-1)
    else:
        print(nn)
    
