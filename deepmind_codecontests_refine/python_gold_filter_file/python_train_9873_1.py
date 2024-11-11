n,a,b=map(int,input().split())

count=0

for i in range(n+1):
    if a<=sum(map(int,str(i)))<=b:
        count+=i

print(count)
