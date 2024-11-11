n = int(input())
l = list(map(int,input().split()))

count = 0
l.sort()


for i in range(len(l)):
    count = (i+1) - l[i] + count
    
print(count)