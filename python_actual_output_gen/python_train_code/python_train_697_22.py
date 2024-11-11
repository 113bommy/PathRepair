n,k = map(int , input().split())
a=list(map(int , input().split()))
queue=[]
for i in range(n):
    if a[i] in queue:
        continue
    if len(queue)<k:
        queue.insert(0,a[i])
    else:
        queue.pop()
        queue.insert(0,a[i])
print(len(queue))
print(queue)