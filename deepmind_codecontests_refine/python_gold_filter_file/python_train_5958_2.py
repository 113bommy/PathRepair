t=int(input())
 
ans_list=[]
for i in range(t):
    n,g,b=map(int,input().split())
    need_way = (n+1)//2
    need_days = (need_way//g)*(g+b)

    if need_way%g==0:
        need_days-=b
    else:
        need_days+=need_way%g
    
    ans_list.append(max(n,need_days))
 
for g in range(t):
    print(ans_list[g])