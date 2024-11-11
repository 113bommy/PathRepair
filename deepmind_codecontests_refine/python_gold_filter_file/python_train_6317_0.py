n,k = map(int, input().split());
a = [None] * n;
completed = 0;

a = input().split();
for i in range(0,n):
    a[i] = int(a[i]);

front = 0;
end = n-1;

while a[front]<=k and len(a)>0:
    #print(a, front);
    if a[front]<=k:
        del a[front];
        completed+=1;
        end = len(a)-1;
    if len(a)<=0:
        break;

if len(a)>0:
    while a[end]<=k and len(a)>0:
        #print(a, end);
        if a[end]<=k:
            del a[end];
            completed+=1;
            end = len(a)-1;
        if len(a)<=0:
            break;

print(completed);