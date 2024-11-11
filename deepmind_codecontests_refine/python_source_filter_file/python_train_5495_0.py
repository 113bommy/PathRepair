k,n = map(int,input().split())
A = list(map(int,input().split()))

B=[]
t=0
for a in A:
    B.append(a-t)
    t=a
B[0] +=k-t

print(B, k-max(B) )