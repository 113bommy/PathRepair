a=int(input())
for i in range(a):
    b=int(input())
    arr=[str(i) for i in range(b,1,-1)]
    arr=arr[::-1]
    print(len(arr))
    print(' '.join(arr))
