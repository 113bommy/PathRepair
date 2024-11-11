n , a , b = map(int, input().split())
x = [i for i in range(1, n+1)]
y = x[::-1]
if n==1:
    print(1)

elif b<0:
    z = y.index(a)
    ans = y[z:]
    if len(ans)>=abs(b):
        print(ans[abs(b)-1])
    else:
        p = (abs(b)%n)
        q = p - len(ans)
        ans = ans + y[:q+1]
        print(ans[-1])

else:
    ans = x+x
    b = b%n
    z = ans.index(a)
    ans = ans[z:z+b+1]
    print(ans[-1])