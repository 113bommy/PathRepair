# https://codeforces.com/problemset/problem/1352/F

t=int(input())
for _ in range(t):
    a,b,c = map(int,input().split())
    if not b:
        print('0'*(a+1) if a else '1'*(c+1))
    else:
        ans = "10"*((b+1)//2) + "1"*(b&1)
        print('1'*c + '1' + '0'*a + '0' + ans[2:])