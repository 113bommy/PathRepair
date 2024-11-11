n=int(input())
aa=[]
bb=[]
for i in range(n):
    a,b=map(int,input().split())
    aa.append(a)
    bb.append(b)
aa.sort()
bb.sort()
if(n%2==0):
    print(bb[n//2-1]+bb[n//2]-aa[n//2]-aa[n//2-1]+1)
else:
    print(bb[n//2]-aa[n//2]+1)