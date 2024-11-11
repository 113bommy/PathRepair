n=int(input())
begins1=[]
ends1=[]
begins2=[]
ends2=[]
for i in range(n):
    begin,end=[int(x) for x in input().split()]
    begins1.append(begin)
    ends1.append(end)
m=int(input())
for i in range(m):
    begin,end=[int(x) for x in input().split()]
    begins2.append(begin)
    ends2.append(end)
begins1.sort()
ends1.sort()
begins2.sort()
ends2.sort()
print(max(0,begins2[m-1]-ends1[0],begins1[n-1]-ends2[0]))
