for _ in range(int(input())):
    n=int(input())
    a=[int(o) for o in input().split()]
    even=[]
    odd=[]
    k=0
    for i in a:

        if i%2==0:
            even.append([i,k])
        else:
            odd.append([i,k])
        k+=1
    j=0
    if j<n-1:
        for i in range(len(even)//2):
            print(even[2*i][1],even[2*i+1][1])
            j+=1
            if j==n-1:
                break
    if j<n-1:
        for i in range(len(odd)//2):
            print(odd[2*i][1],odd[2*i+1][1])
            j+=1
            if j==n-1:
                break
    
    
