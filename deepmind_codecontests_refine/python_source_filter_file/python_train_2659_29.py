n,m = list(map(int, input().split()))
h = list(map(int, input().split()))
count = 0
for i in h:
    if i<m:
        count+=1
    else:
        count+=2
print(count)
    