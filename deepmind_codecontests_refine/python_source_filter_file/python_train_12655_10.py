
def helppolycarp(days,a,k,i=0,mcount=0):
    if(i+1==days):
        a.append(mcount)
        return a

    if(((a[i+1]+a[i]))<k):
        #print("hi",a)
        #print("i+1",i+1)
        #print("hello",abs(((a[i+1]+a[i])-k))+a[i+1] )
        #print("mcount",mcount)

        mcount=abs(((a[i+1]+a[i])-k))+mcount
        #print("up mcount", mcount)
        a[i+1]=abs(((a[i+1]+a[i])-k))+a[i+1]
        #print("a=",a)
        #print()
        return helppolycarp(days,a,k,i+1,mcount)
    else:
        return helppolycarp(days,a,k,i+1,mcount)






days,k=input().split()
days=int(days)
k=int(k)

a=list(map(int,input().split()))
ans=helppolycarp(days,a,k)
#print("ans",ans)
print(ans[len(ans)-1])
ans.pop()
for i in range(0,len(ans)):
    print(ans[0],end=" ")
