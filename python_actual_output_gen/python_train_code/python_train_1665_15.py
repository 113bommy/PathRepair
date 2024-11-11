for _ in range(int(input())):
    a,b,c = map(int,input().split())
    at,bt,ct = 1,1,1
    ans = 10**12
    for i in range(1,10**4+1):
        for j in range(i,10**4+1,i):
            for k in range(j,10**4+1,j):
                s = abs(a-i)+abs(b-j)+abs(c-k)
                if ans>s:
                    ans = min(ans,s)
                    A,B,C = i,j,k
                    #print(ans,i,j,k)
    print(ans)
    print(A,B,C)