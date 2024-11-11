def fct(x, y, a , b):
    if (y - x) % (b + a) == 0: return (y - x) / (b + a)
    return -1

t = int(input())
while (t > 0):
    x, y, a, b = map(int, input().split())
    print(fct(x,y,a,b))
    t -= 1