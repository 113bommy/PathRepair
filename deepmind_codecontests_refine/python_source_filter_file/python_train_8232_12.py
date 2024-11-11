n,h,a,b,k = map(int,input().split())
for i in range(k):
    ta,fa,tb,fb = map(int,input().split())
    ans=0
    if ta==tb:
        print(abs(fa-fb))
        exit()
    elif a<=fa<=b:
        ans = abs(tb-ta) + abs(fb-fa)
    elif fa>b:
        ans = abs(tb-ta) + abs(fa-b) + abs(b-fb)
    elif fa<a:
        ans = abs(tb-ta) + abs(a-fa) + abs(a-fb)
    print(ans)      