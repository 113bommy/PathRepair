n = int(input())
r = dict()
# h kh u oo
for i in range(n):
    s = input()
    w = ""
    k = 0
    o = 0
    for c in s:
        if c not in ("h", "k", "u", "o"):
            if k > 0:
                w += "k" * k
                k = 0
            if o > 0:
                w += "(" + str(o) + ")"
                o = 0
            w += c
        if c == "h":
            if o > 0:
                w += "(" + str(o) + ")"
                o = 0
            if (k > 0):
                k = 0
            w += "h"
        if c == "k":
            if o > 0:
                w += "(" + str(o) + ")"
                o = 0
            k += 1
            
        if c == "u":
            if k > 0:
                w += "k" * k
                k = 0
            o += 2
        if c == "o":
            if k > 0:
                w += "k" * k
                k = 0
            o += 1
    if k > 0:
        w += "k" * k
        k = 0
    if o > 0:
        w += "(" + str(o) + ")"
        o = 0
    #print(s, w)
    r[w] = r.get(w, 0) + 1
print(r)
print(len(r))
    