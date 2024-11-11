n=int(input())
A=list(map(int,input().split()))
B=[abs(i) for i in A]
P=0
for i in A:
    if i<0:P +=1
    elif i==0:print(sum(B));exit()

print(B if P%2==0 else sum(B)-2*min(B))