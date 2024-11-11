n=int(input())
l=list(map(int,input().split()))
l.sort()
total=0
cnt=0
for i in l:
    if total<=i:
        cnt+=1
    total+=i
print(cnt)
    
