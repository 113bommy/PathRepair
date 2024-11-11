
n = int(input())
smW = 0
mxH1 = 0
mxH2 = 0
widths = []
heights = []
for i in range(n):
    w,h = map(int,input().split(" "))
    widths.append(w)
    heights.append(h)
    smW += w
    if h > mxH2 and h < mxH1:
        mxH2 = h
    elif h > mxH1:
        mxH2 = mxH1
        mxH1 = h

for i in range(n):
    if heights[i] == mxH1:
        print((smW-widths[i])*mxH2 ,end = " ")
    else:
        print((smW-widths[i])*mxH1 ,end = " ")
print()
        