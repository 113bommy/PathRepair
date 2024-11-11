import operator as a
input()
l=sorted([[p,i,0] for i,p in enumerate(map(int,input().split()))])
for i in range(len(l)):l[i][2]=i%2
for (a,b,c) in sorted(l,key=a.itemgetter(1)):print(c,end='')