from collections import defaultdict
n=int(input())
dict1=defaultdict(int)
m1=10000
m2=0
set1=set()
i1=0
i2=0
list1=[]
for i in range(n):
    x=int(input())
    if(x<m1):
        m1=x
        i1=i+1
    if(x>m2):
        m2=x
        i2=i+1
    dict1[x]+=1
    set1.add(x)

if(n==1):
    print("Exemplary pages.")
elif(n==2):
    if(len(set1)==1):
        print("Exemplary pages.")
    elif((m2-m1)%2==0):
        print(str((m2-m1)//2)+" ml. from cup #"+str(i1)+" to cup #"+str(i2)+".")
    else:
        print("Unrecoverable configuration.")
else:
    if(len(set1)==1):
        print("Exemplary pages.")
    elif(len(set1)==3 and (m2-m1)%2==0 and dict1[m1]==1 and dict1[m2]==1 and ((m2-m1)//2) in set1):
        print(str((m2-m1)//2)+" ml. from cup #"+str(i1)+" to cup #"+str(i2)+".")
    else:
        print("Unrecoverable configuration.")