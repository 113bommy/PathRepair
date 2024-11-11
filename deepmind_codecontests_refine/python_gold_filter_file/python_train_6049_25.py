"""https://codeforces.com/contest/1040/problem/A"""
n,a,b = tuple(map(int, input().split()))
suits = list( map(int, input().split()))

i,j=0,n-1
cost = 0
while i<j:
    if suits[i]==suits[j]:
        if suits[i]==2:
            cost+=(2*min(a,b))
    else:
        if suits[i]==2:
            if suits[j]==1:
                cost+=b
            else:
                cost+=a
        elif suits[j]==2:
            if suits[i]==1:
                cost+=b
            else:
                cost+=a
        else:
            print(-1)
            exit()
    i+=1
    j-=1
if i==j and suits[i]==2:
    cost+=min(a,b)
print(cost)