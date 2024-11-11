n, k = map(int,input().split())
c = 0
t = (k)*(k-1)
if n>t:
    print("NO")
else:
    print("YES")
    for i in range(1,n):
        for j in range(i+1,n):
            print(i,j)
            c+=1
            if c==n:
                break
            print(j,i)
            c+=1
            if c==n:
                break
        if c==n:
            break
