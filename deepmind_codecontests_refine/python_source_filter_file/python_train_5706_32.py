import queue

"""
N = int(input())
#S = input()
# (N,M) = (int(i) for i in input().split(" "))
# A = [int(i) for i in input().split()]
A = []
for i in range(N):
	A.append(int(input()))

print(A)

"""
def s(time,maxX,minX,maxY,minY,maxU,minU,maxD,minD,maxL,minL,maxR,minR):
	mxx = []
	mnx = []
	mxy = []
	mny = []
	if maxX != None:
		mxx.append(maxX)
		mnx.append(minX)
	if maxY != None:
		mxx.append(maxY)
		mnx.append(minY)
	if maxR != None:
		mxx.append(maxR+time)
		mnx.append(minR+time)
	if maxL != None:
		mxx.append(maxL-time)
		mnx.append(minL-time)
	if maxU != None:
		mxy.append(maxU+time)
		mny.append(minU+time)
	if maxD != None:
		mxy.append(maxD-time)
		mny.append(minD-time)
	mxx = max(mxx)
	mnx = min(mnx)
	mxy = max(mxy)
	mny = min(mny)
	return (mxx-mnx)*(mxy-mny)

N = int(input())

E = [[t if i==2 else int(t) for i,t in enumerate(input().split(" "))]for _ in range(N)]
U = [d[0:2] for d in E if d[2]=="U"]
D = [d[0:2] for d in E if d[2]=="D"]
L = [d[0:2] for d in E if d[2]=="L"]
R = [d[0:2] for d in E if d[2]=="R"]

if len(U+D)>0:
	maxX = max(U+D,key=lambda x:x[0])[0]
	minX = min(U+D,key=lambda x:x[0])[0]
else:
	maxX=None
	minX=None

if len(L+R)>0:
	maxY = max(L+R,key=lambda x:x[1])[1]
	minY = min(L+R,key=lambda x:x[1])[1]
else:
	maxY=None
	minY=None

if len(U)>0:
	maxU = max(U,key=lambda x:x[1])[1]
	minU = min(U,key=lambda x:x[1])[1]
else:
	maxU=None
	minU=None

if len(D)>0:
	maxD = max(D,key=lambda x:x[1])[1]
	minD = min(D,key=lambda x:x[1])[1]
else:
	maxD=None
	minD=None

if len(L)>0:
	maxL = max(L,key=lambda x:x[0])[0]
	minL = min(L,key=lambda x:x[0])[0]
else:
	maxL=None
	minL=None

if len(R)>0:
	maxR = max(R,key=lambda x:x[0])[0]
	minR = min(R,key=lambda x:x[0])[0]
else:
	maxR=None
	minR=None

watch = [0]
min_ans = s(0,maxX,minX,maxY,minY,maxU,minU,maxD,minD,maxL,minL,maxR,minR)

if maxU != None:
	if maxY != None:
		if minY > maxU:
			watch.append(minY-maxU)
		if minY > minU:
			watch.append(minY-minU)
		if maxY > maxU:
			watch.append(maxY-maxU)
		if maxY > minU:
			watch.append(maxY-minU)
	if maxD != None:
		if minD > maxU:
			watch.append((minD-maxU)/2)
		if maxD > maxU:
			watch.append((maxD-maxU)/2)
		if minD > minU:
			watch.append((minD-minU)/2)
		if maxD > minU:
			watch.append((maxD-minU)/2)
if maxD != None:
	if maxY != None:
		if minY < maxD:
			watch.append(maxD-minY)
		if minY < minD:
			watch.append(minD-minY)
		if maxY < maxD:
			watch.append(maxD-maxY)
		if maxY < minD:
			watch.append(minD-maxY)


if maxR != None:
	if maxX != None:
		if minX > maxR:
			watch.append(minX-maxR)
		if minX > minR:
			watch.append(minX-minR)
		if maxX > maxR:
			watch.append(maxX-maxR)
		if maxX > minR:
			watch.append(maxX-minR)
	if maxL != None:
		if minL > maxR:
			watch.append((minL-maxR)/2)
		if maxL > maxR:
			watch.append((maxL-maxR)/2)
		if minL > minR:
			watch.append((minL-minR)/2)
		if maxL > minR:
			watch.append((maxL-minR)/2)
if maxL != None:
	if maxX != None:
		if minX < maxL:
			watch.append(maxL-minX)
		if minX < minL:
			watch.append(minL-minX)
		if maxX < maxL:
			watch.append(maxL-maxX)
		if maxX < minL:
			watch.append(minL-maxX)

for t in watch:
	p = s(t,maxX,minX,maxY,minY,maxU,minU,maxD,minD,maxL,minL,maxR,minR)
	if p < min_ans:
		min_ans = p

print(min_ans)































