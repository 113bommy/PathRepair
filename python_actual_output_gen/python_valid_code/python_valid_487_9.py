t=int(input())
for i in range(t):
    s=input()
    l=len(s)
    if(l%2==0):
        k=''
        a=''
        l=l-1
        m=int(l/2)
        for j in range(m):
            k=k+s[j]
        f=m+1
        while(f<=l):
            a=a+s[f]
            f=f+1
        if(a==k):
            print('YES')
        else:
            print('NO')
    else:
        print('NO')