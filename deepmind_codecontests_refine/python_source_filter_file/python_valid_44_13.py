from collections import defaultdict
for _ in range(int(input())):
    c,d=map(int,input().split())
    a,b=0,0
    if(c==0 and d==0):
        print(0)
        continue
    if(abs(c-d)%2==0):
        print(-1)
        continue
    if(c==d):
        print(1)
        continue
    else:
        print(2)
    
