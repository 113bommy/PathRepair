p,m=map(int,input().split())
b=set()
for i in range(p):
    k=set(input())
    if len(k)>1 or k>b:
        print("NO")
        exit(0)
    b=k
print("YES")
