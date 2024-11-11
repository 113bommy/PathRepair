t=input()
for i in range(int(t)):
    k=0
    n=input()
    a=list(map(int,input().split()[:2*int(n)]))
    for j in a:
        if j%2==1:
            k=k+1
    if k%2==0:
        print("Yes")
    else:
        print("No")

