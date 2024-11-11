#573_D

n = int(input())

ln = [int(i) for i in input().split(" ")]

ln = sorted(ln)

f = False
if ln[-1] == 0:
    print("cslnb")
    f = True
elif len(ln) > 1:
    if ln[1] == 0:
        print("cslnb")
        f = True
        
if not f:
    at = False
    d = False
    ps = ln[0]
    ln2 = ln[:]
    ln2[0] = 0
    for i in range(1, len(ln)):
        if ln2[i] - ln2[i - 1] >= 2:
            ps += ln2[i] - ln2[i - 1] - 1
            ln2[i] = ln2[i - 1] + 1
        if ln[i] == ln[i - 1]:
            if d:
                at = True
            elif i == 1 and ln[0] < 2:
                at = True
            elif i > 1:
                if ln[i - 2] == ln[i - 1] - 1:
                    at = True
                else:
                    d = True
            else:
                d = True
                
    if ps % 2 == 0 or at:
        print("cslnb")
    else:
        print("sjfnb")
