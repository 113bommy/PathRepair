l=[]
t=1
while len(l)!=1000:
    if list(str(t))[len(list(str(t)))-1]!="3" and t%3!=0:
        #print("k")
        l.append(t)
    t+=1
print(l)
for _ in range(0,int(input())):
    a=int(input())
    #b=list(map(int,input().split()))
    print(l[a-1])
