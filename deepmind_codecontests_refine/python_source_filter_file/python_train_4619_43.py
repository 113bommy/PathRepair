count = 0
a = int(input())
for i in range(a):
    l = list(map(int,input().strip().split()))
    if(l.count('1')>=2):
        count+=1
print(count)