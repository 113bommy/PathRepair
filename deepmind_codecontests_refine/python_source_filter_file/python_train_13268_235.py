count=1
for _ in range(int(input())):
    to,tt=list(map(int,input().split()))
    if tt-to>1:
        count+=1
print(count)
    