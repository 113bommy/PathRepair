t=int(input())
for _ in range(t):
    n=int(input())
    l=input()
    c=0
    for i in range(len(l)-1):
        if(l[i]=='A'):
            c=1
            break
    if(c==0):
        print("0")
    else:
        idx=0
        for i in range(len(l)):
            if(l[i]=="A"):
                idx=i
                break
        a=0
        ma=0
        for i in range(idx,len(l)-1):
            if(l[i]=="P" and l[i]==l[i+1]):
                a+=1
            else:
                if(l[i+1]=="P"):
                	a+=1
                if(ma<a):
                    ma=a
                a=0
  
        if(l[len(l)-1]=="P"):
        	a+=1
        if(ma<a):
            ma=a
            a=0
        print(ma)
            
                