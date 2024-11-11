l=lambda :map(int,input().split())
n,k=l()
for i in range(n):
    print('0 '*i+str(k),'0 '*(n-1-i))