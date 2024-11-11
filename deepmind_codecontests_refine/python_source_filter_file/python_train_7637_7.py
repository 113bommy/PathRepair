#python33

def program():
    a=[]
    t=0
    n=int(input())
    for i in range(n):
        a.append(int(input()))
        t=a[0]+1
    for j in range(1,len(a)):
        t+=abs(a[j]+a[j-1])
    print (t)    
program()       
