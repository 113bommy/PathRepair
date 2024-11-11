n,a,b=map(int,input().split())

sum=0

for i in range(n+1):
    if a<=sum(map(int,str(i)))<=b:
        count+=i

print(sum)