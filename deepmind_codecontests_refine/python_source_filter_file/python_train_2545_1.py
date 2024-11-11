# n = int(input())
# l = list(map(int,input().split()))
x1,y1,x2,y2 = map(int,input().split())
if x1==x2:
    d = abs(y2-y1)
    print(x1+d,y1,x2+d,y2)
elif y1==y2:
    d = abs(x2-x1)
    print(x1,y1+d,x2,y2+d)
elif (x2-x1)!=(y2-y1):
    print(-1)
else:
    print(x1,y2,x2,y1)