from bisect import bisect_left,bisect_right
for _ in range(1):
    n,m,t_a,t_b,k=map(int,input().split())
    a_b=list(map(int,input().split()))
    b_c=list(map(int,input().split()))
    for i in range(n):
        a_b[i]+=t_a
    count=0
    mini=-1
    if k>=n or k>=m:
        print(-1)
        continue
    for i in range(min(n-1,k+1)):
        c=k-count
        if c >=0:
            value=bisect_left(b_c,a_b[i])
            if value +c >=m:
                mini=-1
                break
            else:
                mini=max(mini,b_c[value+c]+t_b)
        if mini ==-1:
            break
        count+=1
    print(mini)