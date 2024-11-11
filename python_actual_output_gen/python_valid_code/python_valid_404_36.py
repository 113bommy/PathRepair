n=int(input())
avail=0
for i in range(n):
    a,b=map(int,input().split())
    if a<(b+1):
        avail+=1
print(avail)
