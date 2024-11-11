n=int(input())
a=[]

def v2(n,l):
    n=str(n)
    if len(n)==1:
        if not(int(n) in l[0] or int(n) in l[1]):
            return int(n)-1
        return -1
    elif len(n)==2:
        if not(((int(n[0]) in l[0]) and (int(n[1]) in l[1])) or((int(n[1]) in l[0]) and (int(n[0]) in l[1]))):
            return int(n)-1
        return -1

def v3(n,l):
    n=str(n)
    if len(n)==1:
        if not(int(n) in l[0] or int(n) in l[1] or int(n) in l[2]):
            return int(n)-1
        return -1
    elif len(n)==2:
        if not(((int(n[0]) in l[0]) and (int(n[1]) in l[1])) or((int(n[0]) in l[0]) and (int(n[1]) in l[2]) or ((int(n[0]) in l[1]) and (int(n[1]) in l[2])) or ((int(n[0]) in l[1]) and (int(n[1]) in l[0])) or ((int(n[0]) in l[2]) and (int(n[1]) in l[0])) or ((int(n[0]) in l[2]) and (int(n[1]) in l[1])))):
            return int(n)-1
        return -1
    else:
        if not(  ((int(n[0]) in l[0]) and (int(n[1]) in l[1]) and (int(n[2]) in l[2]))  or  ((int(n[0]) in l[0]) and (int(n[1]) in l[2]) and (int(n[2]) in l[1]))   or   ((int(n[0]) in l[1]) and (int(n[1]) in l[0]) and (int(n[2]) in l[2]))  or ((int(n[0]) in l[1]) and (int(n[1]) in l[2]) and (int(n[2]) in l[0]))  or    ((int(n[0]) in l[2]) and (int(n[1]) in l[0]) and (int(n[2]) in l[1])) or ((int(n[0]) in l[2]) and (int(n[1]) in l[1]) and (int(n[2]) in l[0]))):
            return int(n)-1
        return -1
               
    
   






for i in range(n):
    r=0
    l=list(map(int,input().split()))
    a.append(l)

if n==1:
    for i in range(min(a[0]),9):
        if not i in a[0]:
            print(i-1)
            break
    
elif n==2:
    for i in range(1,100):
        if v2(i,a)!=-1:
            print(v2(i,a))
            break
        
else:
    for i in range(1,1000):
        if v3(i,a)!=-1:
            print(v3(i,a))
            break


        
