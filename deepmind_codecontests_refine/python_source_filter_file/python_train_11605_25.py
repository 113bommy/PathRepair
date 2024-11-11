a,m=map(int,input().split())
for i in range(25):
    a=(a+(a%m))%m
    if a==0: print('YES'); break
else: print("NO")