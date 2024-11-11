N=int(input())

q=[-1]*N
for i in range(N):
    k = int(input())
    print(k)
    q[k-1]=i


max_con=1
count=0
for i in range(N-1):
    if q[i]<q[i+1]:
        count+=1
        max_con=max(max_con,count)
    else:
        count=1

print(N-max_con)