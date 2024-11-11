t= int(input())
for i in range(t):
    n= int(input())
    ans= []
    cur= 4*n
    for j in range(n-1, 0, -1):
        ans.append(cur)
        cur-= 2 
    print(*ans)