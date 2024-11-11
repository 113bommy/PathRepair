for _ in range(int(input())):
    n = int(input())
    a = set([int(i) for i in input().split()])
    flag=0
    for i in range(1,max(a)+1):
        st=set()
        for j in a:
            st.add(j^i)
        if st==a:
            flag=1
            break
    if flag==1: print(i)
    else: print(-1)
            