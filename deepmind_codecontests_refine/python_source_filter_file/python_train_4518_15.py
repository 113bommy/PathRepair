a,b,n=map(int,input().split())
flag=0
for i in range(-1000,1001):
    if a*i**2==b:
        print(i)
        flag=1
        break
if flag==0:
    print("No solution")