t=int(input())
for i in range(t):
    n,s,k=[int(i) for i in input().split(' ')]
    a=[int(i) for i in input().split(' ')]
    for j in range(n):
        if ((((s-j) in a)==0)and(s-j>0))or((((s+j) in a)==0)and(s+j>0)):
            print(j)
            break
