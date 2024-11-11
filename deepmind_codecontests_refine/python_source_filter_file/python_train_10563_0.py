n,m=map(int,input().split(" "))
di={}
for i in range(m):
    a,b=map(str,input().split(" "))
    di[a]=b
li=list(map(str,input().split(" ",n)[:n]))
st=""
for i in range(len(li)):
    # if li[i] in di.keys():
    if len(li[i])<len(di[li[i]]):
        st+=li[i]
    else:
        st+=di[li[i]]
    # else:
    #     if len(li[i])<len(di.keys()[di.values().index(li[i])]):
    #         st+=li[i]
    #     else:
    #         st+=di.keys()
    st+=" "
print(st)