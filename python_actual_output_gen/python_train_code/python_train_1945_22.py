n=int(input())
A=[map(int,input().split())]
s=0
for i in A:
 s+=1/i
print(1/s)