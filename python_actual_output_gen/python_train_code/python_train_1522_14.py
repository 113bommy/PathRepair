neck = []
brace = []
t = int(input())
for z in range(t):
    neck = []
    brace = []
    n = int(input())
    a = input().split()
    b = input().split()
    neck = [int(i) for i in a]
    brace = [int(i) for i in b]
    lneck = len(neck)
    lbrace = len(brace)
    for i in neck:
        if i < 0:
            lneck=-1
    for i in brace:
        if i < 0:
            lbrace=-1
    if lneck !=n or lbrace!=n:
        break
    neck.sort()
    brace.sort()
    add = [neck[i]+brace[i] for i in range(len(neck))]
    if len(add) == len(set(add)):
        print(neck)
        print(brace)