n=int(input())
for j in range(1,n+1):
    t=(j*(j+1))//2
    if j==n:
        print("YES")
        break
    elif t>n:
        print("NO")
        break