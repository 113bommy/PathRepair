for t in range(int(input())):
    v=input()
    x=0
    c=1
    while c!=0:
        c=0
        for i in range(len(v)-1):
            h=v[i]
            if v[i+1]!=h:
                v=v[0:i]+v[i+2:]
                c=1
                x+=1
                break
    if x%2==0:
        print("NET")
    else:
        print("DA")        
