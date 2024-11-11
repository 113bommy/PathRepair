a,b=map(str,input().split())

def mask(x):
    st=''
    for i in str(x):
        if i=='7' or i=='4':
            st+=i
    return(st)


for i in range(int(a)+1,177778):
    if mask(i)!=b:
        pass
    else:
        print(i)
        quit()
