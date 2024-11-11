n,d = map(int,input().split(" "))
hei = list(map(int,input().split()))
hei.sort()
count = 0
for i in range(n):
    for j in range(i+1,n):
        if hei[i]- hei[j]<= d:
            count+=1
print(2*count)