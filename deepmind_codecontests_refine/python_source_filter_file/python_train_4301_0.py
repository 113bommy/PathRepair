def r(str):
    s =""
    for i in str:   
        if(i=="2"):
            s = "5" + s
        elif(i=="5"):
            s= "2" +s
        else:
            s = i +s
        
    return s 

def solve():
    
    l1=list(input().split())
    h = l1[0]
    m = l1[1]
    
    l2=list(input().split(":"))
    h1 = l2[0]
    m1 = l2[1]
    
    valid = ["1","2","5","8","0","00","01","02","05","08","10","11","12","15","18","20","21","22","25","28","50","51","52","54","58","80","81","82","85","88","100"]
    
    
    if(((h1 in valid) and (int(r(h1))<int(m)) )and ((m1 in valid) and (int(r(m1))<int(h)))):
        print(h1+":"+m1)
    elif(h1 not in valid or int(r(h1))>=int(m)):
        while((h1 not in valid) or (int(r(h1))>=int(m)) ):
            h1 = str((int(h1)+1) % int(h))
            if(int(h1) in [0,1,2,3,4,5,6,7,8,9]):
                h1 = "0"+h1
        if(int(h1) in [0,1,2,5,8]):
            print("0{}:00".format(int(h1)))
        else:
            print("{}:00".format(h1))
    else:
        while((m1 not in valid) or  (int(r(m1))>=int(h))):
            m1 = str((int(m1)+1)%int(m))
            if(int(m1) in [0,1,2,3,4,5,6,7,8,9]):
                    m1 = "0"+m1
            if(int(m1)==0):
                break
        if(int(m1)==0):
            h1 = str((int(h1)+1) % int(h))
            if(int(h1) in [0,1,2,3,4,5,6,7,8,9]):
                h1 = "0"+h1
            while((h1 not in valid) or (int(r(h1))>=int(m)) ):
                h1 = str((int(h1)+1) % int(h))
                if(int(h1) in [0,1,2,3,4,5,6,7,8,9]):
                    h1 = "0"+h1
            if(int(h1) in [0,1,2,5,8]):
                print("0{}:00".format(int(h1)))
            else:
                print("{}:00".format(h1))
        else:
            if(int(m1) in [1,2,5,8]):
                print("{}:0{}".format(h1,int(m1)))
            else:
                print("{}:{}".format(h1,m1))
t =int(input())
while(t):
    solve()
    t =t-1