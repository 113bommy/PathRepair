t=int(input())
for k in range(t):
    a,b=map(int,input().split())
    ans=0
    #print("a=", a, "b=", b)
    if a > b :
        ans=b*b
    else:
        d=b//a
        #print("d=",d)
        ans += (d+1)**2*(b%a)   #不整除部分
        ans += d**2*(a-b%a)     #整除部分
    print(ans)
