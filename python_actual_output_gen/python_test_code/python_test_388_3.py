def mex(a):
    '''
    Returns MEX of set(a)
    MEX = minimum excludant
    The min number from 0 excludant from set
    '''
    mex = 0
    while mex in a:
        mex += 1
    return mex

n, x = list(map(int, input().split()))
a = set(map(int, input().split()))
mexa = mex(a)
counter = 0
if mexa > x:
    print(mexa - x)
else:
    for i in range(mexa, x):
        if i not in a:
            counter += 1
    if x in a:
        counter += 1
    print(counter)
