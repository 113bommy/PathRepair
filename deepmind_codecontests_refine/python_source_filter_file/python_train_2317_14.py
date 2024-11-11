t =int(input())
for i in range(t):
    n=int(input())
    even=[]
    odd=[]
    arr = [int(x) for x in input().split()]
    for x in range(len(arr)):
        if x%2==0:
            even.append(x+1)
        else:
            odd.append(x+1)
    if len(even)%2==0:
        if len(even)>=2:
            even.pop()
            even.pop()
        else:
            odd.pop()
            odd.pop()
    else:
        even.pop()
        odd.pop()
    merged=even+odd
    for k in range(0,len(merged)-1,2):
        print(merged[k],merged[k+1])
