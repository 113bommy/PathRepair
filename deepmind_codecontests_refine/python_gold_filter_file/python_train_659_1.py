#A. Two Bags of Potatoes
y,k,n = map(int,input().split())
flag = True
init = (y+k)%k
init = y+k-init
for x in range(init,n+1,k):
    flag = False
    print(x-y,end=' ')
if flag:
    print(-1)