n=int(input())
l=list(map(int, input().split()))
ans=0
ll=[]
for i in range(len(l)-1):
    if l[i]*2 >= l[i+1]:
        #print("ekcnen")
        #print(ans)
        ans+=1
    else:
        if ans >0:
            ans +=1
            #print(ans,"ans at appedn")
            ll.append(ans)
            ans=0
ans+=1
ll.append(ans)
#print(ll)       
if len(ll)==0:
    print(1)
else:
    print(max(1,max(ll)) )
