a,b,k=map(int,input().split())
for i in range(a,min(b+1,a+k)):
    print(i)
for i in range(max(a,b-k+1),b+1):
    print(i)