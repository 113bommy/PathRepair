n,q=map(int,input().split())
l=[0 for i in range(n)]
for i,v in enumerate(list(input().replace("AC","X!"))):
    l[i]=l[i-1]+(v=="!")
for c in range(q):
    h,m=map(int,input().split())
    print(l[m-1]-l[h-1])