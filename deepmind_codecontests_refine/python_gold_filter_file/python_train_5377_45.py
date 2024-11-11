n = int(input())
count = 0
for i in range(1,n):
    k = n-i
    if k%i==0:
        count+=1

print(count)