n = int(input())
l = list(map(int,input().split()))

l.sort()
j = [0]*(10**6+1)

for i in l:
    j[i] += 1
    if j[i] == 1:
        for k in range(2*i,10**6+1,i):
            j[k] += 100

print(j.count(1))