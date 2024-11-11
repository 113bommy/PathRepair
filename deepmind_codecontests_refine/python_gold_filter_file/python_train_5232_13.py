for _ in " "*int(input()):
    a=int(input())
    b=list(map(int,input().split()))
    c=sorted(range(a),key=lambda x:b[x])
    cnt=ans=1
    for i in range(1,a):
            if c[i]>c[i-1]:
                cnt+=1
            else:
                ans=max(ans,cnt)
                cnt=1
    print(a-max(ans,cnt))