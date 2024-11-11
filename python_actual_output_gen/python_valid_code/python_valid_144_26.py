# import sys
# sys.stdin=open('input.in','r')
# sys.stdout=open('output.out','w')
n,m=input().strip().split()[:2]
n=int(n)
m=int(m)
count=0
l=list(map(int,input().strip().split()[:n]))
l.append("$#%#")
for x in range(len(l)-2):
	if l[x+1]-l[x]>m:
		count=1
	else:
		count+=1
print(count)

