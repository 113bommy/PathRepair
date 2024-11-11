n=int(input())
times=[int(z) for z in input().split()]
times.sort()
times=times[::-1]
res=times[0]
for i in range(1,n):
    times[i]=min(times[i],times[i-1]-1)
    res+=times[i]
print(res)