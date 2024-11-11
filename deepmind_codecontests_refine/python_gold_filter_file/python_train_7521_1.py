t=int(input())
while(t):
    n=int(input())
    l=list(map(int,input().split()))
    st=[]
    x=97
    for i,v in enumerate(l):
        if i==0:
            v=v or 1
            st.append('a'*v)
        else:
            if l[i-1]==0:
                x+=1
                if x>122:
                    x=98
                v=v or 1
                st.append(chr(x)*v)
            else:
                if v<l[i-1]:
                    st.append(st[i-1][:l[i-1]])
                else:
                    x+=1
                    if x > 122:
                        x=99
                    st.append(st[i-1][:l[i-1]]+chr(x)*max(0,v-l[i-1]))

    if l[-1]==0:
        x+=1
        if x>122:
            x=98
        st.append(chr(x))
    else:
        st.append(st[-1][:l[-1] or 1])
    print("\n".join(st))
    t-=1
            

