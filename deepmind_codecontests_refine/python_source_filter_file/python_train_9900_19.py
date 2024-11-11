n,k = map(int,input().split())
if(k<=2):
    print('0')
    exit(0)
elif(k < n):
    print((k)//2)
else:

    print( max(((2*n-k)+1)//2, 0))
    #1 2 3 4 5
    # (2n-k)+1 // 2
