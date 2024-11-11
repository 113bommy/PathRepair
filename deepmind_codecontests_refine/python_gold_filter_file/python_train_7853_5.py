loop = int(input())

s = str(input())
e = s.split(" ")

for i in range(loop):
    e[i] = int(e[i])

maxDiff = max(e)-min(e)
countOne = 0
countTwo = 0
i=0
e.sort()
while e[i]==e[0]:
    countOne+=1
    i+=1
    if i==loop:
        break
i=loop-1
while e[i]==e[-1]:
    countTwo+=1
    i-=1
    if i==0:
        break
if maxDiff >0:
    print(str(maxDiff)+" "+str(countOne*countTwo))
elif maxDiff==0:
    print("0 "+str(int((loop-1)*loop/2)))