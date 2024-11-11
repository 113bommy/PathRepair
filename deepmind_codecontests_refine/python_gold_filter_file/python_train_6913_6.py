n,k=map(int,input().split())
if k==0 and n>1:
    print("No solution")
elif k==0 and n==1:
    print(0)
else :
    print(k+9*(10**(n-1)-1))