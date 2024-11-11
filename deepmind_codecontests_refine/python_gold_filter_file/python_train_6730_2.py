n = int(input())
r = input()
a = list(map(int,r.split()))
x,y = max(a),min(a)
t = [0,0,0]
if x - y < 2:
    print(n)
    print(r)
else:
    for i in a:
        if i == x:
            t[0] += 1
        elif i == y:
            t[2] += 1
    t[1] = n-t[0]-t[2]
    if t[1]//2 > min(t[0],t[2]):
        print(n-2*(t[1]//2))
        s = [str(x)]*(t[0]+t[1]//2)+[str(x-1)]*(t[1]-2*(t[1]//2))+[str(y)]*(t[2]+t[1]//2)
        print(' '.join(s))
    else:
        print(n-2*min(t[0],t[2]))
        s = [str(x)]*(t[0]-min(t[0],t[2]))+[str(x-1)]*(t[1]+2*min(t[0],t[2]))+[str(y)]*(t[2]-min(t[0],t[2]))
        print(' '.join(s))