while 1:
    w,h=map(int,input().split())
    if w==0 and h==0: break
    for a in range(h):
        print('#'*w)
    print()
