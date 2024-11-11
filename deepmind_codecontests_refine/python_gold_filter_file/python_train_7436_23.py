n, k = map(int,input().split())
s = input()
if k > n // 2:
    for j in range(k,n):
        print("RIGHT")
    for i in range(n,1,-1):
        print("PRINT",s[i-1])
        print("LEFT")
    print("PRINT",s[0])
else:
    for j in range(1,k):
        print("LEFT")
    for i in range(n-1):
        print("PRINT",s[i])
        print("RIGHT")
    print("PRINT",s[-1])
