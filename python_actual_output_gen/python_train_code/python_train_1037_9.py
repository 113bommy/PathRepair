n,s=list(map(int,input().split()))
if n-sum([int(x) for x in str(n)])<s:
    print(0)
else:
    def check(n):

        # print(n-sum([int(x) for x in str(n)])>s)
        return (n-sum([int(x) for x in str(n)]))>s
    start=1
    end=n
    mid=(start+end)//2
    while mid !=end and mid!=start:

        if check(mid):
            end=mid
            mid=(start+end)//2
        else:
            start=mid
            mid = (start + end) // 2
            # print(start,mid,end)
    print(n-end+1)
