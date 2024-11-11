n=int(input())
adj=[[] for i in range(n)]
for i in range(1,n):
    s=int(input())
    adj[s-1].append(i)
def chk(l):
    c=0
    st=True
    for i in adj[l]:
        if adj[i]==[]:
            c+=1
        else:
            st=st and chk(i)
    if st and c==3:
        return True
    return False
ans =chk(0)
if ans:
    print("Yes")
    exit()
print("No")
