n=int(input())
arr=[0]*9
s=input()
for c in s:
    if c=='L':
        for i in range(9):
            if arr[i]==0:
                arr[i]=1
                break
    elif c=='R':
        j=8
        while j>=0:
            if arr[j]==0:
                arr[j]=1
                break
            j-=1
    else:
        arr[int(c)]=0
    #print(arr)
for i in arr:
    print(i,end="")