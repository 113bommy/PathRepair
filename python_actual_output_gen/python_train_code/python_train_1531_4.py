"""Python 3.3"""
numStation = int(input())
distance = [int(x) for x in input().split()]
wantDis = [int(x) for x in input().split()]
wantDis2 = sorted(wantDis)
wantDis = sorted(wantDis)
check1 = 0
while wantDis[1]>wantDis[0]:
	check1+=distance[wantDis[1]-2]
	wantDis[1]-=1
check2 = 0
while wantDis2[1]<=	numStation:
	check2+=distance[wantDis2[1]-1]
	wantDis2[1]+=1
count = 1
while count<wantDis2[0]:
	check2+=distance[count]
	count+=1
print(min(check1,check2))



