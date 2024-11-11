n,m,k=map(int,input().split())
power=list(map(int,input().split()))
school=list(map(int,input().split()))
chose=list(map(int,input().split()))
count=0
for i in chose:
    for j in range(n):
        if school[j]==school[i-1] and power[j]>power[i-1]:
            count+=1
            break
print(count)