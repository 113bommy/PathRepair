n=int(input())
while(n):
    n-=1
    x,y,a,b =map(int,input().split())
    my = (y - x) / (a + b)  if (y - x) % (a + b)== 0 else  -1
    print(my)