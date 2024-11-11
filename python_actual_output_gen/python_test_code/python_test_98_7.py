def base(n,b):
    global st
    
    if(n<b):
        st.append(n)
        return 
    
    base(n//b,b)
    st.append(n%b)
    return  
st=[]
def proC(m,w):
    global st
    st=[]
    base(m,w)
    s=0
    c=0
    arr=st
    for i in range(len(arr)):
        s=(int(arr[i])+c)%w
        c=(int(arr[i])+c)//w
        
        if(s==0 or s==1):
            continue
        if(s==w-1):
            c=1
        else:
            print('NO')
            return 
    print('YES')
w,m=list(map(int,input().split()))
proC(m,w)