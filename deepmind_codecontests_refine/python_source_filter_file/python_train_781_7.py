lll=input().split()
n=int(lll[0])
k=int(lll[1])
q=int(lll[2])
ll=input().split()
l=list(map(int,ll))
s=[]
u=0
for i in range(k):
    s.append((0,0))
while u<q:
    u+=1
    o=input().split()
    if o[0]=="1":
        t=(int(o[1]),l[int(o[1])-1])
        #print(t)
        for j in range(k):
            if t[1]>s[j][1]:
               s.pop()
               s.insert(j,t)
               break
        #print(s)
    elif o[0]=="2":
        rr=0
        for j in range(k):
            if s[j][0]==int(o[1]):
                print("Yes")
                rr=1
                break
        if rr==0:
            print("No")