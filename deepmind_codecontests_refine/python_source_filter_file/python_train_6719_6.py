n,a= map(int,input().split())
t = list(map(int,input().split()))
count = 0
a = a-1
if t[a] == 1:
    count+=1
for i in range(1,n-a+1):
    if a-i >= 0 and a+i <n:
        if t[a-i] == 1 and t[a+i] ==1:
            count+=2
    elif a-i < 0 and a+i <n:
        if t[a+i] == 1:
            count+=1
    elif a-i >=0 and a+i >=n:
        if t[a-i] == 1:
            count+=1
print(count)