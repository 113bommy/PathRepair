a,b=map(int,input().split())
n=list(map(int,input().split()))
n.sort(reverse=True)
n[0:b]=[]
print(sum(n))  
