n,k = map(int,input().split())
for i in range(n):
    print("0 " * (n-i-1) + str(k) + " 0" * i)
