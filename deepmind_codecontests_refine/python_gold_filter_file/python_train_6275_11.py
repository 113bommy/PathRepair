for _ in range(int(input())):
    n = int(input())
    ans=1000000000000
    c=0
    for i in range(1,min(1000000,n+1)):
        c+=1
        cur = i-1 + n//i -1 + int(n%i!=0)
        if cur<=ans:
            ans=cur
        else:
            break
    print(ans)