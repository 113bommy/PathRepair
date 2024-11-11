a,b = map(int, input().split())
if(b-a+1 >= 10):
    print(0)
else:
    ans = b%10
    for i in range(b-1,a,-1):
        ans = (ans * i)%10
    print(ans)
