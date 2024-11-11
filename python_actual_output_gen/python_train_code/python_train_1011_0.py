n = int(input())


e = [int(i)-1 for i in input().split()]
v = [int(i) for i in input().split()]
counter = 0

for i in range(n):
    if v[e[i-1]] != v[i]:
        counter+=1
        
print(counter)