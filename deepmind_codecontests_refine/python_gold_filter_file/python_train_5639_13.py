n=int(input())
count=0
l=[]
for i in range(n):
    ai,bi = map(int,input().split())
    count+= bi-ai
    l.append(count)   
l.sort()
print(l[n-1])
