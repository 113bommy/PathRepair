n=int(input())
if n==0:
    print("0")
else:
    print(3**(n-1)%1000003)