def fu():
    n=(input())
    di={}
    s=set()
    s2=[]
    for i in n:
        if i not in di:
            di[i]=1
        else:
            di[i]=di[i]+1
        s.add(i)
    if len(s)>4:
        print("NO")
        return
    for i in di:
        s2.append(di[i]) 
    
    if(len(s)==1):
        print("NO")
        return
    if(len(s)==2):
        if 1 in s2:
            print("NO")
            return

    if(len(s)==3):
        for j in s2:
            if j>1:
                print("YES")
                return
            
        print("NO")
        return
    print("YES")
    
    
             
fu()



































