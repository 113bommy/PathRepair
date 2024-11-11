n,y = map(int,input().split());x=[];y-=1
x.extend(map(int,input().split()))
poin = 0
while poin < y and poin < n :
    poin += x[poin]
if poin == y :
    print("YES")
else : print("NO")