from sys import stdin
a=stdin.readline().split()
n=int(a[0])
k=int(a[1])
A=stdin.readline().split()
B=stdin.readline().split()
sum=0
temp=0

for l in range(0,len(A)):
    if int(B[l])==1:
        sum+=int(A[l])

for p in range(0,k):
    if int(B[p])==0:
        temp+=int(A[p])

MAX=temp

for q in range(k,len(A)):
    if int(B[q-k])==0:
        temp-=int(A[q-k])


    if int(B[q])==0:
        temp+=int(A[q])


    MAX=max(MAX,temp)



print(MAX+sum)