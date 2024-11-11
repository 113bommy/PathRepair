li=set()
def addi(n):
    if n>10**9:
        return 
    li.add(n)
    addi(n*10+4)
    addi(n*10+7)
addi(4)
addi(7)
li=list(set(li))
li.sort()
#print(len(li))
l,r=map(int,input().split())
ans=0
for x in li:
    #print(x)
    if x>=r:
        #print("l",l)
        ans+=x*(r-l+1)
        #print("ans",ans)
        break
    elif x>=l:
        ans+=x*(x-l+1)
        #print("ans",ans)
        l=x+1
print(ans)
