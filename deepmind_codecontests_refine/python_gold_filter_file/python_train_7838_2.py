n=int(input())
l=list(map(int,input().split()))
l.sort()
l.reverse()
sum=0
j=0
for i in range(12):
    if sum>=n:
        break
    sum += l[i]
    j += 1
if sum<n:
    print('-1')
else:
    print(j)

