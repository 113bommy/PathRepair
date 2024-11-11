n,s= map(int, input().split())
if s<n:
    print(1)
elif s//n!=0:
    print(s//n+1)
elif s//n==0:
    print(s//n)

