n=int(input())
count=0
for i in range(n):
    p,q=map(int,input().split())
    if q>p:
        count+=1
print(count)        