for t in range(int(input())):
    n=int(input())
    arr=[int(k) for k in input().split()]
    even=[]
    odd=[]
    pc=0
    for i in range(2*n):
        if arr[i]%2==0:
            even.append(int(i+1))
        else:
            odd.append(int(i+1))
    for j in range(1,len(even)-1,2):
            pc+=1
            if pc<n:
                print(even[j-1],end=" ")
                print(even[j])
    for j in range(1,len(odd)-1,2):
            pc+=1
            if pc<n:
                print(odd[j-1],end=" ")
                print(odd[j])
    
