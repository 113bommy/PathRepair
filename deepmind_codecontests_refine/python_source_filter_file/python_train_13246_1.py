
'''test=int(input())
for i in range(test):
    a,b,c,d=[int(i) for i in input().split(" ")]
    x,y,x1,y1,x2,y2=[int(i) for i in input().split(" ")]
    ans1=0
    ans2=0
    if abs(x-x1)>=a and abs(x2-x)>=b:
        ans1=1
    elif abs(x-x1)>=a:
        if abs(x2-(x-a))>=b:
            ans1=1
    elif abs(x2-x)>=b:
        if abs(x+b-x1)>=a:
            ans1=1
    if abs(y-y1)>=c and abs(y2-y)>=d:
        ans2=1
    elif abs(y-y1)>=c:
        if abs(y2-(y-c))>=d:
            ans2=1
    elif abs(y2-y)>=d:
        if abs(y+d-y1)>=c:
            ans2=1
    
    if ans1&ans2:
        print("YES")
    else:
        print("NO")'''

'''b=int(input())
s1=[int(i) for i in input().split(' ')]
g=int(input())
s2=[int(i) for i in input().split(" ")]
s1.sort()
s2.sort()
ans=0
for i in range(b):
    for j in range(g):
        if abs(s1[i]-s2[j])<=1:
            s2[j]=1000
            ans+=1
            break
print(ans)
'''

#CF 639

'''test=int(input())
for i in range(test):
    n,m=[int(i) for i in input().split()]
    if n==1:
        print("YES")
    elif '''


'''test=int(input())
def value(t):
    return (t*(3*t+1))/2
def f(x):
    if x<2:
        return 0
    elif x==2:
        return 1
    else:
        h=1
        k=2
        
        while k<=x:
            h+=1
            k=value(h)
        card_used=value(h-1) if k!=x else k
        return 1+f(x-card_used)

for i in range(test):
    n=int(input())
    
    ans=f(n)
    #print(value(4))
    print(ans)  
    '''

#CF  640 (DIV-4)

'''test=int(input())
for i in range(test):
    n=int(input())
    ans=[]
    c=0
    while n:
        k=10**(c)
        ans.append((n%10)*k)
        c+=1
        n=n//10
    tes=[i for i in ans if i]
    print(len(tes))
    for j in tes:
        print(j,end=" ")'''

'''test=int(input())
for i in range(test):
    n,k=[int(i) for i in input().split()]'''


'''test=int(input())
for i in range(test):
    n,k=[int(i) for i in input().split()]
    jump=n-1
    if k<n:
        rank=k
    else:
        rank=k+int((k-1)//(n-1)) 
    
   
    print(rank)'''



'''test=int(input())
for i in range(test):
    n=int(input())
    arr=[int(i) for i in input().split()]
    i=-1
    j=n
    rem=n
    alice=0
    bob=0
    prev=0
    flag=1
    cnt=0
    while rem>0 and j!=i:
        gain=0
        if flag:
            while gain<=prev and rem>0 and i!=j:
                i+=1
                gain+=arr[i]
                rem-=1
            flag=0
            alice+=gain
            prev=gain

        else:
            while gain<=prev and rem>0 and j!=i:
                j-=1
                gain+=arr[j]
                rem-=1
            flag=1
            bob+=gain
            prev=gain
        cnt+=1
    print(cnt,alice,bob,sep=" ")
    '''

#CF 641

'''test=int(input())
def f(n):
    i=2
    while i**2<=n:
        if n%i==0:
            return i
        i+=1
    return n


for i in range(test):
    n,k=[int(i) for i in input().split()]
    if n%2:
        n+=f(n)
        n+=2*(k-1)
    elif not n%2:
        n+=2*(k)
    print(n)'''

test=int(input())
for i in range(test):
    n=int(input())
    arr=[int(i) for i in input().split()]
    dp=[1]*(n)
    for i in range(len(arr)-1,-1,-1):
        flag=0
        intial=2
        mul=(i+1)*2
        while mul<len(arr):
            if arr[mul]>arr[i]:
               dp[i]=max(dp[i],1+dp[mul])
            intial+=1
            mul=(i+1)*intial
    print(max(dp)) 

