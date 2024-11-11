from math import inf
bound = [-10**9,10**9]
for i in range(int(input())):
    x, y, z = input().split()
    y=int(y)
    if x == ">" and z=="Y":bound[0]=max(bound[0],y+1)
    if x == ">" and z=="Y":bound[1]=min(bound[1],y)
    if x == ">=" and z=="Y":bound[0]=max(bound[0],y)
    if x == ">=" and z=="N":bound[1]=min(bound[1],y-1)
    if x == "<" and z=="Y":bound[1]=min(bound[1],y-1)
    if x == "<" and z=="N":bound[0]=max(bound[0],y)
    if x == "<=" and z=="Y":bound[1]=min(bound[1],y)
    if x == "<=" and z=="N":bound[1]=max(bound[0],y+1)

print("Impossible"if bound[0]>bound[1] else bound[0])