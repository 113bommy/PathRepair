
#common prefixes
'''
for _ in range(int(input())):

    n=int(input())

    l=list(map(int,input().split()))
    s=[]

    s1=''
    for i in range(51):
        s1+=chr(97)

    k=0
    s.append(s1)
    
    for i in range(n):
        s1=''
        for j in range(51):
            if j==l[i]:
                k=ord(s[i][j])-97
                k+=1
                k=k%26
                s1+=chr(97+k)
                
            else:
                s1+=str(s[i][j])
        s.append(s1)

    for i in range(n+1):
        print(s[i])
'''

#string transformation 1
'''
for _ in range(int(input())):

    n=int(input())
    s1=input()
    l1=list(s1)
    
    s2=input()
    l2=list(s2)

    ans=0
    q=0

    for i in range(n):
        if s1[i] > s2[i]:
            ans=-1
            break

        else:
            q=ord(s1[i])-96

    if ans==-1:
        print("-1")

    else:
        for i in range(97,97+q):
            mnn='t'
            temp=[]

            for j in range(n):
                if l1[j]!=l2[j] and l1[j]==chr(i):
                    temp.append(j)
                    mnn=min(l2[j],mnn)

            if len(temp)!=0:

                ans+=1
                for j in temp:
                    l1[j]=mnn

        print(ans)
'''

#ternary string
'''
def valid(mid,s):

    t=[0,0,0,0]

    for i in range(mid-1):
        fre=int(s[i])
        t[fre]+=1

    for i in range(mid-1,len(s)):
        fre=int(s[i])
#        print(fre)
        t[fre]+=1

        if t[1]>0 and t[3]>0 and t[2]>0:
            return True

        fre=int(s[i-mid+1])
        t[fre]-=1
        
    return False
        
def binary(s):

    res=float('inf')

    l=3
    r=len(s)

    while l<=r:
        mid=(l+r)//2

        if valid(mid,s):
            res=mid
            r=res-1
            
        else:
            l=mid+1

    if res==float('inf'):
        return 0
    else:
        return res
            
for _ in range(int(input())):

    s=input()

    print(binary(s))
    
'''

#maximum GCD
'''
for _ in range(int(input())):

    n=int(input())

    if n>=2:
        ans=int(n/2)

    else:
        ans=1

    print(ans)
'''

#GCD compression
'''
import math

for _ in range(int(input())):

    n=int(input())

    l=list(map(int,input().split()))

    even=[]
    odd=[]
    d=2*n
    
    for i in range(d):
        if l[i]%2==0:
            even.append(i)

        else:
            odd.append(i)

    count=0

    for i in range(0,len(even)-1,2):
        print(even[i]+1,even[i+1]+1)
        count+=1
        if count==n-1:
            break

    if count<n-1:
        for i in range(0,len(odd)-1,2):
            print(odd[i]+1,odd[i+1]+1)
            count+=1
            if count==n-1:
                break
'''

'''
def combinationutil(arr,n,r,index,data,i):

    if index==r:
        for j in range(r):
            print(data[j],end=" ")

        print(" ")
        return


    if i>=n:
        return


    data[index]=arr[i]
    combinationutil(arr,n,r,index+1,data,i+1)

    combinationutil(arr,n,r,index,data,i+1)
    
    
def printcomb(arr,n,r):

    data=list(range(r))

    combinationutil(arr,n,r,0,data,0)

    
arr=[10,20,30,40,50]
r=3
n=len(arr)
printcomb(arr,n,r)

'''


#number game
'''
def calculate(n):

    count1=0
    
    while n%2==0:
        n=n//2
        count1+=1

    if n==1:
        print('FastestFinger')

    elif count1>1:
        print('Ashishgup')

    elif count1==1:
        for i in range(3,n+1,2):
            if n%i==0:
                n=n//i
                if n!=1:
                    count=2
                    break
                else:
                    count=1
                    break

        if count==1:
            print("FastestFinger")

        else:
            print("Ashishgup")
    
for _ in range(int(input())):

    n=int(input())

    if n>1 and n%2==1:
        print("Ashishgup")

    elif n==2:
        print("Ashishgup")
    elif n==1:
        print("FastestFinger")

    else:

        calculate(n)

'''     

#alternating subsequence
'''
for _ in range(int(input())):

    n=int(input())

    l=list(map(int,input().split()))

    su=i=mxx=0
    
    while i<=n-1:
        mxx=-pow(10,18)
        if l[i]>0:
            
            j=i
            while j<n and l[j] > 0 :
                if mxx<l[j]:
                    mxx=l[j]
                j+=1

            su+=mxx
            i=j

        else:
            j=i
            while(j<n and l[j]<0):
                if mxx<l[j]:
                    mxx=l[j]
                j+=1

            su+=mxx
            i=j

    print(su)
'''

#Nastya and strange generator
'''
for _ in range(int(input())):

    n=int(input())
    l=list(map(int,input().split()))

    index=[0]*(n+1)
    
    for i in range(n):
        index[l[i]]=i
        
    count=[1]*n
    
    r=[i for i in range(n)]

    t=index[1]
    flag=0
    
    for i in range(1,n+1):
        if index[i]!=t:
            flag=1
            break
        
        count[index[i]]=0


        j=index[i]
        while j<n and count[j]==0:
            j+=1

#        print(j)
        if j<n:
            r[index[i]]=j
            count[j]+=1
        else:
            r[index[i]]='X'


        if j<n:
            t=j

        else:
            if i+1<n+1:
                t=index[i+1]

    if flag==1:
        print("No")

    else:
        print("Yes")

'''

#Weights distributing   tle
'''
from collections import defaultdict
class graph:

    def __init__(self,v):
        self.vertex=v
        self.graph=defaultdict(list)

    def add(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def bfs(self,s,l):

        queue=[]
        l[s]=0
        queue.append(s)

        while(len(queue)!=0):
            node=queue.pop(0)

            for item in self.graph[node]:
                if l[item]==float('inf'):
                    l[item]=l[node]+1
                    queue.append(item)


for _ in range(int(input())):

    n,m,a,b,c=map(int,input().split())

    a-=1
    b-=1
    c-=1
    
    l=list(map(int,input().split()))
    l.sort()

    pref=[0]*(m+1)

    for i in range(m):
        pref[i+1]=pref[i]+l[i]

    g=graph(n)
    for i in range(m):
        q,w=map(int,input().split())
        g.add( q-1,w-1 )

    da=[float('inf')]*n
    db=[float('inf')]*n
    dc=[float('inf')]*n

    g.bfs(a,da)
    g.bfs(b,db)
    g.bfs(c,dc)

    ans=float('inf')

    for i in range(n):
        if da[i]+db[i]+dc[i]<=m:
            ans = min(ans, pref[db[i]]+pref[da[i] + db[i] + dc[i]])

    print(ans)

'''

#Lcm
'''
for _ in range(int(input())):

    l,r=map(int,input().split())

    if l*2>r:
        print('-1','-1')

    else:
        print(l,l*2)

'''

#Two polygon
'''
for _ in range(int(input())):

    n,m=map(int,input().split())

    if n%m==0:
        print("YES")

    else:
        print("NO")

'''

#XXXXX
'''
for j in range(int(input())):

    n,x=map(int,input().split())

    l=list(map(int,input().split()))

    pre=[0]*(n+1)
    suf=[0]*(n+1)

    mxx1=mxx2=-1
    
    suf[n]=l[n-1]

    if suf[n]%x!=0:
        mxx2=n
#    print(mxx2)
    
    for i in range(1,n+1):
        pre[i]=pre[i-1]+l[i-1]
        if pre[i]%x!=0:
            mxx1=i
#            print(mxx1)
            
        suf[n-i]=suf[n-i+1]+l[n-i-1]
#        print(suf[n-i],'t2')
        if suf[n-i]%x!=0 and n-i!=0:
            
            mxx2=n-i
#            print(mxx2)
            

    suf[0]=0

    k=n+1-mxx2
#    print(k)
    
    if mxx1>0:
        if mxx2>0:
            print(max(mxx1,k))

        else:
            print(mxx1)

    else:
        print('-1')

'''

#1-08-2020


#Buying Shovels
'''
import math

def factors(n):
    t=int(math.sqrt(n))

    ans=0
    
    for i in range(2,t+1):
        if n%i==0:
            if n//i!=i and n//i<=k:
                ans=n//i
                break

            elif i<=k:
                ans=i

    return ans

for _ in range(int(input())):

    n,k=map(int,input().split())

    if n<=k:
        ans=n

    else:
        ans=factors(n)
        if ans==0:
            ans=1

    print(n//ans)
        
'''

#Orac and models
'''
for _ in range(int(input())):

    n=int(input())
    l=list(map(int,input().split()))

    k=[0]*n
    
    for i in range(n):
        k[i]=1
        for j in range(i-1,-1,-1):

            if l[i]%l[j]==0 and k[i]<k[j]+1:
                k[i]=k[j]+1


    print(max(k))

'''

#Prime Subtraction
'''   
for _ in range(int(input())):

    x,y=map(int,input().split())

    k=x-y

    if k==1:
        print("NO")

    else:
        print("YES")
'''

#Round Corridor
'''
n1,m1,q=map(int,input().split())

n=n1-2
m=m1-2

a=n//2
b=m//2

for i in range(q):
    s_x,s_y,e_x,e_y=map(int,input().split())
 
    if (n1%2==0 and m1%2==0) or (n1%2==1 and m1%2==1):
        if n1!=m1:
            if s_x==1 and e_x==1:
                if s_y <=a+1 and e_y <=a+1:
                    print("YES")

                elif s_y >a+1 and e+y >a+1:
                    print("YES")

                else:
                    print("NO")

            elif s_x==1 and e_x==2:
                if s_y <=a+1 and e_y<=b+1:
                    print("YES")

                elif s_y >a+1 and e_y >b+1:
                    print("YES")

                else:
                    print("NO")

            elif s_x==2 and e_x==1:
                if s_y<=b+1 and e_y <=a+1:
                    print("YES")

                elif s_y>b+1 and e_y>a+1:
                    print("YES")

                else:
                    print("NO")

            else:
                if s_y<=b+1 and e_y<=b+1:
                    print("YES")

                elif s_y>b+1 and e_y>b+1:
                    print("YES")

                else:
                    print("NO")

        else:
            if s_y == e_y:
                print("YES")

            else:
                print("NO")

    else:
        print("YES")  

'''
#correc one
'''
import math

n,m,q=map(int,input().split())

d=math.gcd(n,m)
a=0,n//d,m//d

for _ in[0]*q:
    u,x,v,y=map(int,input().split())

    if (x-1)//a[u]==(y-1)//a[v]:
        print("YES")

    else:
        print("NO")

'''

#Multiple Table
#wrong approach
'''
def find_gcd(a,b):
    if b==0:
        return a

    return find_gcd(b,a%b)


n=int(input())

l=[[0 for i in range(n)]for j in range(n)]

t=[]

for i in range(n):
    a=list(map(int,input().split()))
    result=0
    for j in range(i,n):
        if i==j:
            l[i][j]=a[i]

        else:
            l[i][j]=a[j]
            l[j][i]=a[j]  

for i in range(n):
    result=0
    for j in range(n):
        result=find_gcd(result,l[i][j])

    t.append(result)

for i in range(n):
    print(t[i],end=" ")

'''
#correct ones
'''
import math
n=int(input())

l=[[0 for i in range(n)]for j in range(n)]

t=[]

for i in range(n):
    a=list(map(int,input().split()))
    result=0
    for j in range(i,n):
        if i==j:
            l[i][j]=a[i]

        else:
            l[i][j]=a[j]
            l[j][i]=a[j]

t.append(int(math.sqrt((l[0][1]*l[0][2])//l[1][2])))
print(t[0],end=" ")

for i in range(1,n):
    a=l[0][i]//t[0]

    print(a,end=" ")

'''

#Submarine in the rybinsk sea
'''

n=int(input())

l=list(input().split())

t=[]
a=len(l[0])
su=0

for i in range(n):
    s=''

    for j in range(a):
        s+=l[i][j]
        s+=l[i][j]

    su+=int(s)
    
q=[0]*(a*2)

for i in range(n):
    s=''
    for j in range(i+1,n):
        
        for k in range(a):
            q[2*k]=l[i][k]
            q[1+(2*k)]=l[j][k]

        x=''.join(q)
        su+=int(x)

        for k in range(a):
            q[2*k+1]=l[i][k]
            q[2*k]=l[j][k]

        x=''.join(q)
        su+=int(x)

print(su%998244353)

'''

#Prime Graph

def prime(n):

    l=[-1]*n
    visited=[False]*n

    visited[0]=True
    visited[1]=True

    p=2
    while p*p < n:
        if visited[p]==False:

            for i in range(p*p,n,p):
                l[i]=p
                visited[i]=True

        p+=1

    d=[]
    
    for i in range(n):
        if not visited[i]:
            d.append(i)

    return d

def binary(k,n,primes):
    start=0
    last=n
    j=0
    
    while start<last:
        mid=(start+last)//2

        if primes[mid]==k:
            return mid

        elif primes[mid]>k:
            last=mid
            j=last

            if primes[last]>n and primes[last-1]<n:
                return last
            
        else:
            start=mid+1
            j=start

            if primes[start]<n and primes[start+1]>n:
                return start+1

    return j
            
n=int(input())

primes=prime(1013)

t=binary(n,len(primes)-1,primes)

print(primes[t])
count=0

for i in range(n):
        
    print((i)%(n+1)+1,(i+1)%(n)+1)
    count+=1

for i in range(primes[t]-count):
    print(i+1,i+1+n//2)
    count+=1

 
    






    


