n = int(input())
arr = list(map(int,input().split()))
was = ["N"]*100500
for i in range(n):
    was[arr[i]-1] = i
m = 99999999999
ind = 0
for i in range(100500):
    if was[i] != "N":
        if was[i] < m:
            m = was[i]
            ind = i
print(ind+1)