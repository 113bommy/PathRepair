def elephant(arr) :
    a=min(arr)
    cnt=0
    for i in range(len(arr)) :
        if a==arr[i] :
            cnt=cnt+1
            q=i
    if cnt==1 :
        print(q+1)
    elif cnt>=2 :
        print("still in rozdil")
    return
n=int(input())
a=[]
a=[e for e in map(int,input().split())]
elephant(a)