a,b=map(int,input().split())
tasks=list(map(int,input().split()))
steps=0
tasks=[1]+tasks
for i in range(1,b+1):
    if tasks[i]>=tasks[i-1]:
        steps+=tasks[i]-tasks[i-1]
    else:
        steps+=tasks[i]-tasks[i-1]+4
print(steps)

