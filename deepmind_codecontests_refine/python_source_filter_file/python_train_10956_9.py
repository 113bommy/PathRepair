
# m = 4
# numbers 0 to 15; median is 7: 0111
# idea: start at median, if 2 are bigger, move down 1, if 2 are smaller, move up 1, check if you are passing over

def dec(b, m):
    return "{:0{}b}".format( int(b, 2) - 1, m )

def inc(b, m):
    return "{:0{}b}".format( int(b, 2) + 1, m )


def median(n, m, a):

    md = '0' + '1' * (m-1)
    state = 1
    
    seen = {}
    for e in a:
        if e > md:
            state -= 1
            if state == -1:
                while True:
                    md = dec(md, m)
                    if md not in seen:
                        break
                state = 1
        elif e < md:
            state += 1
            if state == 2:
                while True:
                    md = inc(md, m)
                    if md not in seen:
                        break
                state = 0
        elif e == md:
            if state == 1:
                while True:
                    md = inc(md, m)
                    if md not in seen:
                        break
                state == 0
            else:
                while True:
                    md = dec(md, m)
                    if md not in seen:
                        break
                state == 1
        seen[e] = 1

    return md



t = int(input().strip())

for _ in range(t):

    n, m = list(map(int, input().strip().split()))

    a = []
    for _ in range(n):
        a.append( input().strip() )

    print(median(n, m, a))

    
