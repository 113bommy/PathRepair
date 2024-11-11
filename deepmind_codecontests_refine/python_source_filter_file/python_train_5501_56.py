a,b,k=map(int,input().split())
for s in range(a+1):
    for t in range(b+1):
        if k==(a-t)*s+(b-s)*t:
            print("Yes")
            exit()
print("No")