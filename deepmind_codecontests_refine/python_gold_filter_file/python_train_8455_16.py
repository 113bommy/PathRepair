for ii in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    if(len(a)>=3):
        temp=0
        idx=0
        idx2=idx+2
        for i in range(0,n):
            idx2=i+2
            idx=i
            while((idx2<len(a))):
                if(a[idx]==a[idx2]):
                    temp=1
                    break
                idx2+=1
            if(temp==1):
                break
        if(temp==1):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
