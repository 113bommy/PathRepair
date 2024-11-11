q = int(input())
for i in range(q):
    a,b,c,d = map(int,input().split())
    print((a//d)+c*(a//d)//b)