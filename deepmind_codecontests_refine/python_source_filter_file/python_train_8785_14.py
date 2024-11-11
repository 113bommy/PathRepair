n = int(input())
n2 = n*n
k = 1
for i in range(1,n+1):
    for j in range(k,k+n//2):
        print(j,n2-j,end=' ')
    print('')
    k += n//2