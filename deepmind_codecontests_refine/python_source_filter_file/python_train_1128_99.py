n = int(input())
a = list(map(int,input().split()))
x = [0]*9
for i in a:
    x[min(i//400,8)]+=1
if x[8]==0:
    print(9-x.count(0),9-x.count(0))
else:
    print(max(1,8-x.count(0)),min(8,8-x.count(0)+x[8]))