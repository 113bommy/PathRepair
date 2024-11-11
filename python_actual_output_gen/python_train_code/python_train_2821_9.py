n, h, a, b, k = map(int, input().split())
for i in range(k):
    ta, fa, tb, fb = map(int, input().split())
    if ta == tb:
        print(abs(fa - fb))
    else:
        if a <= ta <= b:
            print(abs(ta - tb) + abs(fa - fb))
        elif fa > b:
            print(abs(ta - tb) + (fa - b) + abs(b - fb))
        else:
            print(abs(ta - tb) + (a - fa) + abs(a - fb))
