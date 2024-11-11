
d = int(input())
n = int(input())
l = list(map(int,input().split()))

count = 0
sum   = 0
for i in range(1,n):

    if d>l[i]:
        count+=d - l[i]
print(count)


