n = int(input())
p = list(map(int,input().split(" ")))
i = n-2
sum_ = p[n-1]
while(i>0):
    p[i] = max(min(p[i],p[i+1]-1),0)
    sum_+=p[i]
    i-=1
print(sum_)