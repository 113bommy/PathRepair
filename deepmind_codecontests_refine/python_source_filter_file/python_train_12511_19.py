n,k = map(int,input().split())
'''
k <= n*(n+1)//2
'''

total = 1
c = 2
eat = 0
action = n - 1
while action:

    while total == 0 or total < k:
        total+=c
        c+=1
        action-=1
    yy = min(action,total)
    eat+=yy
    action-=yy
    total-=yy

print(eat)

