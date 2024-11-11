n = int(input())
l = [0 for i in range(100)]

for i in range(n):
    a = list(map(int,input().split()))
    
    for i in range(a[0]):
        l[a[1+i]-1] += 1
        
for i in range(len(l)):
    if l[i] == n:
        print(i+1,end = " ")