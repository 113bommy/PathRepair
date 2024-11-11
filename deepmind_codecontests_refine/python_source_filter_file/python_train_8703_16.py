#coding:utf-8

l,r,x,y,k = list(map(int,input().split()))
for i in range(x,y + 1):
    if i * k <= r & i * k >= l:
        print('YES')
        break
else :
    print("NO")