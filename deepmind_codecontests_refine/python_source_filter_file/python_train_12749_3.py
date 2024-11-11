n=2

arr = input()
l = list(map(int,arr.split(' ')))

n=l[0]
arr2 = input()
l2 = list(map(int,arr2.split(' ')))

print(l2)

flag0=0
flagN=0
firstDiff=0
lastDiff=0
gap=0

l2.sort()
maxDiff=0;

for i in range (l[0]-1):

    if l2[i]==0:
        flag0=1;
    elif l2[i]==l[1]:
        flagN=1;


if flag0==0:
    firstDiff=l2[0]

if flagN==0:
    lastDiff=l[1]-l2[l[0]-1]

if lastDiff>=firstDiff:
    gap=lastDiff

if firstDiff>lastDiff:
    gap=firstDiff

for i in range (l[0]-1):
    if l2[i+1]-l2[i] > maxDiff:
        maxDiff=l2[i+1]-l2[i]

if gap>=maxDiff/2:
    print(float(gap),"00000",sep='')
else:
    print(float(maxDiff/2),"00000",sep='')