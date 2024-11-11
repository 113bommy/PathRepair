n = int(input())
if n==0:
    print('1')
elif n>36:
    print(-1)
else:
    ans = '8'*(n//2)
    if n%2==1:
        ans += '9'
    print(ans)