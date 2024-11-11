n,s=map(int,input().split())
A=list(map(int,input().split()))
if (sum(A)-n)<=s:
    print("YES")
else:
    print("NO")