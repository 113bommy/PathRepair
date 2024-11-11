a,b,c=map(int,input().split())
for i in range(101):
    d=i*a
    if (c-d)%b==0 and d<=c:
        print(i)
        exit(0)
print("No")
