def find_T(n):
    a=bin(n)
    m=len(a)
    for i in range(m):
        if a[i]=='1' :
            return(m-i)
    

def find_ans(n):
    s=list(map(int,input().split()))
    b=s[0]
    ans=0 
    for i in range(1,n):
        if s[i]>=s[i-1] :
            b=s[i]
        else:
            ans=max(ans,find_T(b-s[i]))
    return(ans)

for _ in range(int(input())):

    n=int(input())
    print(find_ans(n))

