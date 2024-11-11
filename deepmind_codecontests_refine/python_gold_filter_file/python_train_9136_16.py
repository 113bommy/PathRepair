import bisect

N=int(input())
A=list(map(int,input().split()))
x=0
for i in range(2,N):
    x^=A[i]
#print(x)
if (A[0]+A[1]-x)%2!=0:
    print(-1)
else:
    AND=(A[0]+A[1]-x)//2
    u=AND
    v=AND
    if AND&x!=0:
        print(-1)
        exit()
    t=[i for i in range(40) if x>>i &1==1]
    #print(t)
    k=len(t)//2
    data1=[]
    data2=[]
    for i in range(2**k):
        temp=0
        for j in range(k):
            if i>>j&1==1:
                temp+=2**t[j]
        data1.append(temp)
    for i in range(2**(len(t)-k)):
        temp=0
        for j in range(len(t)-k):
            if i>>j&1==1:
                temp+=2**t[k+j]
        data2.append(temp)

    #print(data1,data2)
    ans=-1
    val=float("inf")
    for test in data1:
        temp=test+u
        #print(temp)
        id=bisect.bisect_right(data2,A[0]-temp)
        if id!=0:
            temp+=data2[id-1]
            if val>A[0]-temp and A[0]>=temp and temp!=0:
                val=A[0]-temp
                ans=temp
        else:
            if val>A[0]-temp and A[0]>=temp and temp!=0:
                val=A[0]-temp
                ans=temp
        #print(val,"jfkdjfd")
        #print(data1,data2,temp)
    #print(data1,data2)

    if val!=float("inf"):
        print(val)
    else:
        print(-1)
