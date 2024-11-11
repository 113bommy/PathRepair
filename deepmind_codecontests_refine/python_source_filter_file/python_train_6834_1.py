k = int(input())
loops = {0:1 ,1:0,2:0,3:0,4:1,5:0,6:1,7:0,8:2,9:1}
if k> 34 :
    print(-1)
else:
    ans = ''
    ans += '8'*(k//2)
    ans += '4' * (k%2)
    print(ans)