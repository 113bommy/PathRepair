n,s=map(int,input().split())
a=[]
for i in range(n):
    h,m=map(int,input().split())
    a.append(h*60+m)
if s<a[0]:
        print('0 0')
        exit()
for i in range(n-1):
    if a[i+1]>a[i]+s+s+1:
        t=a[i]+s+1
        print(str(t//60)+' '+str(t % 60))
        exit()
t=a[n-1]+1+s
print(str(t//60)+' '+str(t % 60))
