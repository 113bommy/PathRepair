n = int(input())
l = list(map(int,input().split()))
pos =  0
total = 0
for i in range(n):
    total = total + l[pos]
    pos = pos + 1
print(total/(n))