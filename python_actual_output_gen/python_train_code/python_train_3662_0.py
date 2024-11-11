n=int(input());l=list(map(int,input().split()))
for i in range(n):
    c=0
    for j in range(i+1,n):
        if l[i+1]>l[i]:
            c+=1
    print(c+1,end=" ")