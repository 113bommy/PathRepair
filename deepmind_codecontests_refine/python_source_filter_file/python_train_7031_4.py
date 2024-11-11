a,b,p1,p2,p3,p4=map(lambda x:int(x),input().split())
tp=min([b,p1-1,p2-1,p3-1,p4-1])
print(max(0,tp-a+1))