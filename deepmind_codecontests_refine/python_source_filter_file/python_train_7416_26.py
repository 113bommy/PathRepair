import bisect
t=int(input())
const=[(3*(i+1)**2+i+1)//2 for i in range(10000)]
for i in range(t):
    n=int(input())
    cnt=0
    while n>=2:
        d=bisect.bisect_right(const,n)
        n-=const[d-1]
        cnt+=1
    print(cnt)