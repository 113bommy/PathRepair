t=int(input())
for i in range(t):
    n=int(input())
    a=[int(x) for x in  list(input())]+[-1]
    st=[n]
    m=[0]*n
    for i in range(n-1,-1,-1):
        while a[st[-1]]>=a[i]:
            st.pop()
        m[i]=st[-1]
        st.append(i)
    prev=0
    arr=[0]*n
    pr=10
    for i in range(n):
        if m[i]==n and a[i]>=prev and a[i]<=pr:
            arr[i]=1
            prev=a[i]
        else:
            pr=a[i]
    for i in range(n):
        if arr[i]!=1:
            if a[i]<prev:
                print('-')
                break
            else:
                arr[i]=2
                prev=a[i]
    else:
        tot=''
        for item in arr:
            tot+=str(item)
        print(tot)
            
