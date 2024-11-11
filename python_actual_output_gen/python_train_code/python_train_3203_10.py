n,d = map(int,input().split())
l = list(map(int,input().split()))
l.sort()
count = 0
print(l)
for i in range(len(l)):
    for j in range(len(l)):
        if(abs(l[i]-l[j])<=d and i!=j):
            count+=1
print(count)