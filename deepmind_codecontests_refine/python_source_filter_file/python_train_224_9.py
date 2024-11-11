ar_max=[]
ar_min=[]
answer=[]
t=int(input())
for i in range(t):
    n=int(input())
    for i in range(n):
        x,y=map(int, input().split())
        
        ar_max.append(x)
        ar_min.append(y)
    if n==1 or min(ar_max)>max(ar_min):
        answer.append(0)
    else:
        
        answer.append(max(ar_max)-min(ar_min))
    #print(max(ar_max),max(ar_min))
    ar_max=[]
    ar_min=[]
for i in range(len(answer)):
    print(answer[i])
