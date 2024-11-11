a = int(input())
for _ in range(a):
    #x,y = map(int, input().split())
    x = int(input())
    li  = list(map(int, input().split()))
    min1 = abs(li[0]- li[1])
    for a in range(x-1):
        for b in range(a+1,x):
            print(a,b)
            if abs(li[a]-li[b]) < min1:
                min1 = abs(li[a]-li[b]) 
    print(min1)
