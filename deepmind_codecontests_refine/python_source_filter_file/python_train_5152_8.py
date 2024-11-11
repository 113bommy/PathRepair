s = input()
N = int(input())
fs = None
for i in range(N):
    ns = input()
    if len(ns) >= len(s):
        if ns[:len(s)]:
            if fs == None:
                fs = ns
            else:
                fs = min( fs, ns )
if fs == None:
    print(s)
else:
    print(fs) 