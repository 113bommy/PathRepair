import math
def Vol(r,h):
    return math.pi * r**2 * h

def main():
    d,h,v,e = map(float,input().split())
    vol = Vol(d/2,h)
    fill = Vol(d/2,e)
    if fill > v:
        print("NO")
    else:
        print("YES")
        print(vol/(v-fill))
main()