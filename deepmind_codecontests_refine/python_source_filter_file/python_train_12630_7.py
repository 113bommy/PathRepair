for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    odd,even=0,0
    for i in range(2*n):
        if a[i]%2==1:
            odd+=1
        else:
            even+=1
    #print(odd,even)
    #print(odd*even)
    ans="Yes" if odd*even==2*n else "No"
    print(ans)
