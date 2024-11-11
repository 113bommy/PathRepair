a,b,k=map(int,input().split())
for s in range(a+1):
    for t in range(b+1):
        if k==(b-t)*s+(a-s)*t:
            print("Yes")
            exit()
print("No")
