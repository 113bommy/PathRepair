from operator import itemgetter
n=int(input())
A=[tuple(map(int,input().split())) for i in range(n)]
B=[tuple(map(int,input().split())) for j in range(n)]
A.sort()
B.sort()
count=0
for i in range(n):
    box=[A[i] for i in range(len(A)) if (A[i][0]<B[i][0]) and (A[i][1]<B[i][1])]
    if any(box):
        box=sorted(box, key=itemgetter(1))
        A.remove(box[-1])
        count +=1
print(count)