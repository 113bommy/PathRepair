import math
def solve():
    d,h,v,e=list(map(int,input().split()))
    if((e*math.pi*d*d)/4>=v):
        print(-1)
    else:
        print("YES")
        print('%.12f'%((math.pi*d*d*h)/(4*v-e*math.pi*d*d)))
solve()