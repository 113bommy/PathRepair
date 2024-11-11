a=list(range(int(input())+1))
for _ in[0]*int(input()):s,t=map(int,input().split(','));a[s],a[t]=a[t],a[s]
for s in a:s and print(s)
