#9B - Running Student
# from math import sqrt
# n - number of bus stops
# vb - velocity of the bus
# vs - velocity of the student
# n,vb,vs=map(int,input().split())
# # 2nd line of input: the x-axis coordinates of the bus stops (x-axis is the road)
# lst=map(int,input().split())
# # (x, y) - coordinates of the University
# x,y=list(map(int,input().split()))
# ans=[]

# for i in range(1,n):
#     t=lst[i]*1.0/vb+sqrt((x-lst[i])**2+(y)**2)/vs
#     print(t)
#     ans.append((t,-i))
# ans.sort()
# #print ans - the index of the optimal bus stop
# print(-ans[0][1]+1)

import math
# n - number of bus stops
# v_bus - velocity of the bus
# v_student - velocity of the student
"""
y
y
y      *Uni(x,y)
y      y x 
y      y  x          S - optimal bus stop
y      y   x
yxxxxxxxxx(S)xxxxxx
"""
n, v_bus, v_student = map(int, input().split())
#2nd line of input: the x-axis coordinates of the bus stops (x-axis is the road)
stops = list(map(int, input().split()))
# 3rd line of input: coordinates of the University, stored in a list
uni = list(map(int, input().split()))
#We will record all the data about possibilities here 
ans = []
#Note: we already now the first bus stop - 0
for i in range(1, len(stops)):
    # t - time that takes the student to reach the university from the current stop
    # t = d/v
    t = stops[i] / v_bus + math.hypot(uni[0] - stops[i], uni[1]) / v_student
    # d - the distance that the student has to cover from the stop to the university
    d = math.hypot(uni[0] - stops[i], uni[1])
    # position - position of the bus stop
    position = i + 1
    ii = (t, d, position)
    ans.append(ii)
# print(ans)
#Find the tuple with the min values; 
#i+1 is irrelevant as smallest i+1 can be < smallest distance
print(min(ans)[2])