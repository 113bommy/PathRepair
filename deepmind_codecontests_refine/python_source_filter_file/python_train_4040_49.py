import heapq
job = list()
salary = list()
n,m = map(int,input().split())

for i in range(n):
    a,b = map(int,input().split())
    job.append(a,b)
    
job.sort(reverse = True)

for x in job:
    s,t = x
    heapq.heappush(salary,t)
    if s - m > 0:
        heapq.heappop(salary)
    else:
        m -= 1

print(sum(salary))
