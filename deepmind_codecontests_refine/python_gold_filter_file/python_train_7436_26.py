n,k=map(int,input().split())
s=input()
if(n<2*k):
    print("RIGHT\n"*(n-k))
    l=len(s)
    for i in range(l-1,0,-1):
        print("PRINT", s[i])
        print("LEFT")
    print("PRINT", s[0])
else:
    print("LEFT\n"*(k-1))
    l=len(s)
    for i in range(0,l-1):
        print("PRINT",s[i])
        print("RIGHT")
    print("PRINT", s[l-1])