n,x,m=map(int,input().split())
a=[]
mod_check_list = [False for _ in range(M)]
a.append(x*x%m)
ind=0
s=0
for i in range(m):
    t=a[i]*a[i]%m
    if mod_check_list[t]:
        ind=a.index(t)
        break
    mod_check_list[t] = True
    a.append(t)
s=sum(a[ind:])
l=len(a)-ind
loop_times = (n-1-ind)//l
answer=loop_times*s
for i in range((n-1-ind)%l):
    answer+=a[i+ind]
print(answer+x+sum(a[:ind]))