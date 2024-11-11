'''http://codeforces.com/contest/186/problem/B'''
n,t1,t2,k = map(int, input().split(" "))
factor = 1- (k/100)
listX = []
for i in range(n):
    a,b = map(int, input().split(" "))
    maxX = max(((a*t1*factor) + (b*t2)),((b*t1*factor)+(a*t2)))
    # print(maxX)
    listX.append(maxX)

maxVal = max(listX)
while (maxVal!=-1):
    indexMax = listX.index(maxVal)
    print(indexMax +1, maxVal)
    listX[indexMax] = -1
    maxVal = max(listX)
