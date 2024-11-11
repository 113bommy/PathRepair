from collections import Counter
def func():
    l=[]
    x,y=map(int,input().split())
    for i in range(y):
        l.append(input())
    ma=0
    ans=-1
    for i in l:
        if i.count('1')!=len(i):
            ma+=1
        else:
            if ma>ans:
                ans=ma
            ma=0
    if ans==-1:
        ans=ma
    print(ans)
t=1
#t=int(input())
for i in range(t):
    func()