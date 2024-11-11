for _ in range(int(input())):
    n,m,k=[int(i) for i in input().split()]
    h=[int(i) for i in input().split()]
    ans="YES"
    for i in range(n-1):
        if h[i]<h[i+1] and h[i+1] - (h[i] + m) > k:
            ans="NO"
            break
        m+=h[i]-max(h[i+1]-k,h[i+1])
    print(ans)