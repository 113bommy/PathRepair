n=int(input())
ar=[int(i) for i in input().split()]
for i in range(n-1):
    if ar[i]%2==1:
        if ar[i+1]!=0: ar[i+1]-=1
        else:
            print('NO')
            exit(0)
if ar[i]%2==0: print('YES')
else: print('NO')