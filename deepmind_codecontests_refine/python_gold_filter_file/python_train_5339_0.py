def tree(arr):
    count=0
    base=[0]*(len(arr)+1)
    for i in range(1,len(arr)):
        if i-1>0 and arr[i]<arr[i-1]:
            count+=1
        base[i]=base[count]+1
    return base[len(arr)-1]

t=int(input())
for i in range(t):
    n=input()
    print(tree(list(map(int,input().strip().split()))))