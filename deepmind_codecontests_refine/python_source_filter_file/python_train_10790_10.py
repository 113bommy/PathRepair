l,r,a=map(int,input().split())
if l>r:
    if a>l-r:
        print(r+r+l-r+(a-l+r)//2*2)
    else:
        print(r+r+a+a)
else:
    if a > r - l:
        print(l + l + r - l + (a - r + l) // 2*2)
    else:
        print(l + l + a + a)