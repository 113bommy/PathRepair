def f(l):       
    res,end = 0,0      
    for i in range(len(l)): 
        end+=l[i] 
        if end<0: end=0
        else:
            if res<end: res=end              
    return res

for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    l1=[]
    l2=[]
    s=l[0]
    for i in range(1,len(l)):
        if(i%2==0):
            s+=l[i]
            l2.append(l[i]-l[i-1])
        else:
            l1.append(l[i]-l[i-1])
    print(s+max(f(l1),f(l2),0))