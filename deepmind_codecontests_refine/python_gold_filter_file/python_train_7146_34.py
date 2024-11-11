#!/usr/bin/env python
# encoding: utf-8

r, x1, y1, x2, y2 = map(int, input().split())
dis = ((x1-x2)**2+(y1-y2)**2)**0.5
if dis >= r:
    print(x1, y1, r)
else:
    if dis == 0:
        x3 = x1+r
        y3 = y1
    else:
        x3 = x1+(x1-x2)*r/dis
        y3 = y1+(y1-y2)*r/dis
    x4 = (x2 + x3)/2
    y4 = (y2 + y3)/2
    print(x4, y4, (r+dis)/2)
