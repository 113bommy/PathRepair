while True:
    d, w, h = [int(x) for x in input().split()]
    minrad = min(d*d+w*w,w*w+h*h,h*h+d*d)
    if minrad == 0:
        break
    n = int(input())
    for i in range(n):
        r = int(input())
        if 4*r*r > minrad:
            print('OK')
        else:
            print('NA')