t=int(input())
for i in range(t):
    c=0
    n,m=input().split()
    n=int(n)
    m=int(m)
    for j in range(n-1):
        p=input()
        if p[m-1]=="R":
            c=+1
    p=input()
    for j in range(m):
        if p[j]=='D':
            c+=1
    
    print(c)