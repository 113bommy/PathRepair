n,m=map(int, input().split())
num=input().split()
for i in range(n):
    num[i]=int(num[i])
sets=set()
res=[int(0) for i in range(n)]

for i in range(n-1, -1,-1):
    sets.add(num[i])
    res[i]=len(sets)
    
num2=[]
for i in range(m):
    print(res[int(input())-1])
