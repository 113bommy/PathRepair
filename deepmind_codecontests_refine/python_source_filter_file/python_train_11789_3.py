t = input()
for j in range(int(t)):
    p = int(input())
    dic0 = {}
    for q in range(p):
        st = input()
        nk = st.split(' ')
        if len(nk) > 1:
            dic0[q+1] = nk[1:]
        else:
            dic0[q+1] = [0]
    unm = []
    pr = [item for item in range(1, p+1)]
    for item in dic0:
        married = False
        for item2 in dic0[item]:
                if pr[int(item2)-1] == int(item):
                    pr[int(item2)-1] = -1
                    married = True
                    break
        if not married:
            unm.append(item)
    if unm:
        print("IMPROVE")
        for item in pr:
            if item != -1:
                print(unm[0], item)
                break
    else:
        print("OPTIMAL")
                
           