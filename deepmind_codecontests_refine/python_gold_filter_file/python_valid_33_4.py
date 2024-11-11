t=int(input())
def sp():
    n=int(input())
    a=list(map(int,input().split()))
    l=[]
    for i in range(n-1):
        l.append(a[i]*a[i+1])
    
    print(max(l))
for i in range(t):
    sp()