n,k,s=[int(i) for i in input().split()]
a=k
if (n-1)*k<s or k>s:
    print("NO")
else:
    print("YES")
    pos=1
    for i in range(k):
        if pos<=(n)/2:
            dist=min((n-1),s-a+1)
            s-=dist
            pos+=dist
        else:
            dist = min((n - 1), s - a + 1)
            s -= dist
            pos -= dist
        a-=1
        print(pos,end=" ")