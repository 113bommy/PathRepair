# cook your dish here
n=int(input())
l=[]
for i in range(n):
    x,y=input().split()
    l.append([int(x),int(y)])
l.sort()
#print(l)
super_points=0
for i in range(1,n-1):
    #print(i,end="")
    cnt=[0,0,0,0]
    #print(l[i])
    for j in range(0,n):
        
        if(l[i][1]==l[j][1] and l[j][0]<l[i][0]):
            cnt[0]+=1
            #print("found left")
            #print(l[j][0],l[j][1])
        
        if(l[j][1]==l[i][1] and l[j][0]>l[i][0]):
            cnt[1]+=1
            #print("found right")
            #rint(l[j][0],l[j][1])
       
        if(l[j][0]==l[i][0] and l[j][1]>l[i][1]):
            cnt[2]+=1
            #print("found up")
            #print(l[j][0],l[j][1])
        if(l[j][0]==l[i][0] and l[j][1]<l[i][1]):
           cnt[3]+=1
           #print("found down")
           #print(l[j][0],l[j][1])
    if(cnt[0]>0 and cnt[1]>0 and cnt[2]>0 and cnt[3]>0):
        super_points+=1
print(super_points)