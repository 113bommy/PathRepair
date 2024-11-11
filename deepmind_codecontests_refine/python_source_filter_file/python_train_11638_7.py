n,k=map(int,input().split())
d=[]
l=[]

for i in range(k):
    d=int(input())
    l.append(map(int,input().split()))
    
x=set(l)
x=list(x)
print(n-len(x))