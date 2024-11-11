for _ in range(int(input())):
    m=input()
    c_1=0
    c_0=0
    pre_1=[0]*(len(m)+1)
    pre_0=[0]*(len(m)+1)
    for i in range(len(m)):
        if(m[i]=="1"):
            c_1+=1
            pre_1[i+1]=c_1
            pre_0[i+1]=c_0
        else:
            c_0+=1
            pre_1[i+1]=c_1
            pre_0[i+1]=c_0
    ans=min(c_0,c_1)        
    for i in range(1,len(m)):
        ans=min(ans,pre_1[i]+c_0-pre_0[i])
        print("ans1",ans)
        ans=min(ans,pre_0[i]+c_1-pre_1[i])
        print("ans2",ans)
    print(ans)    
        
            
        
    