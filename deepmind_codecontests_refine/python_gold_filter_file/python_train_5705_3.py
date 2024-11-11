n,k = map(int,input().split())

ab = []
for i in range(1,n+1):
    a,b=0,0
    if(n%2==1):
        if(i%2==1):
            a,b = i, n + 1 + (n-i)//2
        else:
            a,b = i, 2*n - (i-2)//2
    elif(n%2==0):
        if(i%2==0):
            a,b = i, n + 1 + (n-i)//2
        else:
            a,b = i, 2*n - i//2
    a += k-1
    b += k-1
    ab.append((a+b,a,b))

ab.sort()

ans = []
for i in range(n):
    c = k+2*n+i
    tot,a,b = ab[i]
    if(tot > c):
        print(-1)
        exit()
    ans.append((a,b,c))

print('\n'.join(map(lambda x: ' '.join(map(str,x)), ans) ))