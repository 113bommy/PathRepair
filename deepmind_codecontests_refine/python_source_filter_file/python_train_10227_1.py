t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    d=float(k/2)*(2+(k-1)*2)
    if(float(n)>d and (float(n)-d)%2==0):
        print("YES")
    else:
        print("NO")
        
    