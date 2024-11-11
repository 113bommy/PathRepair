n,y = map(int,input().split());x=[]
x.extend(map(int,input().split()))
poin = 0
while poin < y and poin < n :
    poin += x[poin]+1
if poin == y :
    print("YES")
else : print("NO")