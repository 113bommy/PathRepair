#q1
'''
for _ in range(int(input())):
    l=list(map(int,input().split()))

    x=l[1]
    y=l[2]
    z=l[2]

    print(x,y,z)
'''  
#q2
'''
for _ in range(int(input())):

    x,n,m=map(int,input().split())
    
    while(x>20 and n>0 and x > x//2+10):
        x=x//2+10
        n-=1

    if(x <= m*10):
        print("YES ")
    else:
        print("NO ")
'''

#q3 
'''
def swap(s,j,mi):
    l=list(s)
    temp=l[j]
    l[j]=l[mi]
    l[mi]=temp

    s=''.join(l)

    return s

for _ in range(int(input())):

    s,t=input().split()

    k=0
    for i in range(len(s)):
        if ord(s[i]) < ord(t[i]):
            k=1
            break

        elif ord(s[i]) == ord(t[i]):
            continue

        else:
            mi=i
            for j in range(i+1,len(s)):
                if ord(s[j]) < ord(t[mi]):
                    s=swap(s,j,mi)
                    k=1
                    break
            break
    if k==1:
        print(s)

    else:
        print('---')

'''

#q4
'''
import math

def lcm(n):
    p=n
    t=int(math.sqrt(n))+1
    l=[0]*n
    l[0]=1
    
    while n%2 == 0:
        if n//2==2:
            l[2-1]+=1
        else:
            l[2-1]+=1
            l[(n//2)-1]+=1
        n=n//2

    for i in range(3,t):
        while n%i==0:

            if n//i==i:
                l[i-1]+=1
            else:
                l[i-1]+=1
                l[(n//i)-1]+=1
                
            n=n//i

    print(l)
    d=set()
    for i in range(p):
#        print('1')
        if l[i]!=0:
            d.add(pow((i+1),l[i]))
#            print('2')

    print(d)
    return list(d)
            
n=int(input())

f=lcm(n)
print(f)

if len(f)==1 or len(f)==2:
    print('1',n)

else:
    t1=f[1]
    t2=f[2]
    k=min(t1,t2)
    for i in range(3,len(f)):
        if t1==k:
            t1*=k
        else:
            t2*=k
        k=min(t1,t2)

    print(t1,t2)
        
'''     
        
#q5
'''
for _ in range(int(input())):

    string=input()
    i=0
    de=0
    z=[]
    
    while i<len(string)-2:

        if string[i:i+5]=="twone":
            de+=1
            z.append(i+2)
            i+=5

        elif string[i:i+3]=="one":
            de+=1
            z.append(i+1)
            i+=3

        elif string[i:i+3]=="two":
            de+=1
            z.append(i+1)
            i+=3       
            
        else:
            i+=1

    print(de)
    for i in range(len(z)):
        print(z[i]+1,end=" ")

    print()
'''        

#string modification ****
'''
for _ in range(int(input())):
    n=int(input())

    string=input()

    l=list(string)
    
    for k in range(n):
        first=n-k

        for i in range(first):
            second=i+k

            l[i:second+1:1]=l[second:i-1:-1]
            print(l)

    print(l)

'''

#remove adjacent
'''
n=int(input())

string=input()
l=list(string)
#print(l)
de=0

while(1):
    q=l
    a=[]
    t=0
    
    for i in range(1,len(l)):
        a.append(ord(q[i])-ord(q[i-1]))
    
    if((1 in a) or (-1 in a)) :
        for i in range(len(a)):
            if a[i]==-1:
                l.pop(i-t)
                t+=1
                de+=1
#                print(l)

            elif a[i]==1:
                l.pop(i+1-t)
                t+=1
                de+=1
#                print(l)

        print(l)
        
    else:
        break
print(de)
'''            


#Yet Another Counting Problem
'''
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

    
def solve(r,lcm,b):

    no_of_term=r//lcm
    product=no_of_term*lcm

    tot=r

    if product!=0:

        tot-=min(b,(r-product+1))
        tot-=(no_of_term-1)*b
        
    return tot-min(r,b-1)

for _ in range(int(input())):

    a,b,q=map(int,input().split())
    if a>b:
        a,b=b,a
        
    gc=gcd(a,b)
    product=a*b
    lcm=product//gc
    
    for i in range(q):
        l,r=map(int,input().split())

        ans1=solve(r,lcm,b)
        if l>=b:
            ans2=solve(l-1,lcm,b)
            ans=ans1-ans2
        else:
            ans=ans1
            
        print(ans,end=" ")
    print()
'''

#number game
'''
import math

import math

f='FastestFinger'
a='Ashishgup'
def prime(n):
    
    r=int(math.sqrt(n))+1
    
    if n%2==0 and n!=2:
        return False

    for i in range(3,r):
        if n % i ==0:
            return False
        
    return True
  
def solve(n):

    if n==0 :
        return
    elif n==1:
        return f
    
    dp=[]
    dp.append(0)
    
    
for _ in range(int(input())):

    n=int(input())
    if prime(n) and n>1:
        print("Ashishgup")
    else:
        print(solve(n))

'''

#Ciel and Flowers
'''
l=list(map(int,input().split()))
t=list(l)

su1=0

for i in range(3):
    su1+=int(l[i]/3)
    l[i]=l[i]%3
    
if min(l)!=0: 
    su1+=min(l)

q=min(t)
su2=q

for i in range(3):
    t[i]-=q

for i in range(3):
    su2+=int(t[i]/3)
    
print(max(su2,su1))
'''


#Count Subrectangles
'''
def row(n,m,k,c):

    l=[]
    for i in range(n):
        su=0
        for j in range(k):
            su+=c[i][j]
        l.append(su)

    for i in range():    

n,m,k=map(int,input().split())

a=list(map(int,input().split()))
b=list(map(int,input().split()))

c=[[0 for i in range(m)]for j in range(n)]

for i in range(n):
    for  j in range(m):
        c[i][j]=a[i]*b[j]

row(n,m,k,c)

'''  

#Ciel and Flowers
'''
a,b,c=map(int,input().split())

ans1=a//3+b//3+c//3
ans2=ans3=0

if a>0 and b>0 and c>0:
    a-=1
    b-=1
    c-=1

    ans2=a//3+b//3+c//3

    ans2+=1

if a>0 and b>0 and c>0 :
    a-=1
    b-=1
    c-=1

    ans3=a//3+b//3+c//3

    ans3+=2

print(max(ans1,ans2,ans3))
'''   

#Way Too Long Words
'''
for _ in range(int(input())):

    s=input()
    ans=""
    
    if len(s)>10:
        t=str(len(s)-2)
        ans+=s[0]+t+s[len(s)-1]

    else:
        ans+=s

    print(ans)
'''

#Progress Bar
'''
n,k,t=map(int,input().split())

a1=n*k

a2=t*a1/100

a3=int(a2/k)

s=int(a2-a3*k)

if s>0:
    for i in range(n):
        if i<a3:
            print(k,end=" ")
        elif i==a3:
            print(s,end=" ")
        else:
            print('0',end=" ")

else:
    for i in range(n):
        if i<a3:
            print(k,end=" ")

        else:
            print('0',end=" ")
    
'''

# Required Remainder
'''
for _ in range(int(input())):

    x,y,n=map(int,input().split())
    t1=n//x
    t2=t1*x
#    print(t1,t2)
    
    if y==0:
        print(t2)
    else:
        a=x-y
        
        if y+t2<=n:
            print(y+t2)
        else:
            print(t2-a)
'''   
    
'''
t1=12345//7
print(t1)
t2=t1*7
print(t2)
'''

# Multiply by 2, divide by 6
'''
import math

def factoriation(n):
    k=int(math.sqrt(n))+1
    
    l=[0]*k

    t=0
    l[0]=0
    l[1]=0
    
    
    while n%2==0:
        t+=1
        n=n//2
        
    l[2]=t

    for i in range(3,k):
        t=0
        while n%i==0:
            t+=1
            n=n//i
        l[i]=t
        
        if n==1:
            return l
        else:
            return [0,0,0,0]
        
    return l

for _ in range(int(input())):

    n=int(input())

    if n==6:
        print('1')

    elif n==3:
        print('2')

    elif n==1:
        print('0')
    
    elif n>=9:
        l=factoriation(n)

        if l[3] >= l[2] and l[3]!=0:
            ans=-1
            ans=l[2]
            l[3]=l[3]-l[2]
            l[2]=0

            ans+=l[3]*2

            print(ans)
            
        else:
            print('-1')

    else:
        print('-1')

'''

# Move Brackets
'''
for _ in range(int(input())):

    n=int(input())

    string=input()

    ans=0
    x2=0
    
    for i in range(n):
        if string[i]==')':
            if x2==0:
                ans+=1
            else:
                x2-=1

        elif string[i]=="(":
            x2+=1

    print(ans)
'''      

#Petya and Strings
'''
string1=input().lower()
string2=input().lower()

for i in range(len(string1)):

    if string1[i] > string2[i]:
        print('1')
        break
    elif string1[i] < string2[i] :
        print('-1')
        break
     
    else:
        if i==len(string1)-1:
            print('0')
            break
        else:
            continue
'''

#Helpful maths
'''
string=input()
li=list(string.split("+"))
l=[0]*3

li.sort()

for i in range(len(li)):
    if i!=len(li)-1:
        print(li[i]+'+',end="")
    else:
        print(li[i])
'''

#word capitalisation
'''
string=input()

if ord(string[0])>96:
    print(chr(ord(string[0])-32)+string[1:])

else:
    print(string)
'''

#Boy or Girl
'''
string=input()

l=[0]*26

for i in range(len(string)):
    l[ord(string[i])-97]+=1

k=0
for i in range(26):
    if l[i]>0:
        k+=1

if k%2==0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')
'''

#Translation
'''
s=input()
t=input()

k=""

for i in range(len(s)-1,-1,-1):
    k+=s[i]

if k==t:
    print("YES")
else:
    print("NO")

'''

#Word
'''
string=input()
lower=0
upper=0


for i in range(len(string)):
    if ord(string[i])>96:
        lower+=1

    else:
        upper+=1

if upper>lower:
    print(string.upper())

else:
    print(string.lower())
            
'''

# Anton and Danik
'''
n=int(input())

string=input()

A=0
D=0

for i in range(n):
    if string[i]=="A":
        A+=1
    else:
        D+=1

if A>D:
    print('Anton')
elif A<D:
    print("Danik")

else:
    print("Friendship")
'''

#Football
'''
string=input()
a=b=0

for i in range(len(string)):

    if string[i]=='0':
        a+=1
        b=0

    else:
        b+=1
        a=0

    if a==7 or b==7:
        t=1
        break

    else:
        t=0

if t==1:
    print("YES")
else:
    print("NO")
'''

#Dubstep
'''
string=input()
s=""
i=0
while i<len(string)-2:

    if string[i]=="W" and string[i+1]=="U" and string[i+2]=="B":
        i+=3
        s+=" "

    else:
        s+=string[i]
        i+=1

if i>=len(string):    
    print(' '.join(s.split()))
    
else:
    s+=string[i]
    i+=1
    
    if i>=len(string):
        print(' '.join(s.split()))
    else:
        s+=string[i]
        print(' '.join(s.split()))
'''

#Two_gram
'''
n=int(input())
string=input()

res=0

for i in range(len(string)-1):
    cur=0
    for j in range(i,len(string)-1):

        if string[i]==string[j] and string[i+1]==string[j+1]:
            cur+=1

    if res < cur:

        res=cur
        ans=string[i]+string[i+1]

print(ans)
'''

#Even But Not Even
'''
for _ in range(int(input())):

    n=int(input())
    string=input()
    l=list(string)
    su=0
    
    for i in range(len(string)-1,-1,-1):
        su+=int(l[i])
        if l[i]=="0":
            l.pop(i)
#    print(su)
    if su%2!=0:
        if int(string)%2==0:
            for i in range(len(l)-1,-1,-1):
                if int(l[i])%2==0:
                    l.pop(i)
                else:
                    break
            for i in range(len(l)-2,-1,-1):
                if int(l[i])%2!=0:
                    l.pop(i)
                    break
                
            if len(l)>1:   
                print(''.join(i for i in l))

            else:
                print('-1')
                
        else:
#            print(l)
            for i in range(len(l)-2,-1,-1):
                if int(l[i])%2!=0:
                    l.pop(i)
                    break

            if len(l)>2:
                print(''.join(i for i in l))
            elif len(l)==2 and int(l[0])%2!=0:
                print(''.join(i for i in l))
            else:
                print('-1')

    else:
#        print(su)
        if int(string)%2!=0:
            print(''.join(i for i in l))
        else:
            for i in range(len(l)-1,-1,-1):
                if int(l[i])%2==0:
                    l.pop(i)
                else:
                    break
            if len(l)>1:
                print(''.join(i for i in l))
            else:
                print('-1')

'''

# Delete from the Left
'''
s=input()
t=input()
q=0


i1=len(t)-1
i2=len(s)-1
    
while i1>=0 and i2>=0:
    if s[i2]==t[i1]:
        q+=1
        i1-=1
        i2-=1
            
    else:
        break


su1=len(s)-q
#print(su1,q)
su2=len(t)-q
print(su1+su2)

'''

#Important exam
'''
n,m=map(int,input().split())
k=[]
    
for i in range(n):
    string=input()
    l=list(string)
    k.append(l)

q=list(map(int,input().split()))
su=0

for i in range(m):
    t1=t2=t3=t4=t5=0

    for j in range(n):
        if k[j][i]=="A":
            t1+=1

        elif k[j][i]=="B":
            t2+=1

        elif k[j][i]=="C":
            t3+=1

        elif k[j][i]=="D":
            t4+=1

        else:
            t5+=1

    a=max(t1,t2,t3,t4,t5)
    su+=a*q[i]

print(su)
            
'''

# Letters Rearranging
'''
for _ in range(int(input())):

    string=input()
    t=1
    j=0
    
    for i in range(len(string)-1):
        if string[i] == string[i+1]:
            t+=1
        else:
            j=i+1
            break

    if t==len(string):
        print('-1')
        
    else:
        k=0
        for i in range(len(string)//2):
            if string[i]==string[len(string)-1-i]:
                k+=2

        if len(string)%2==0 and k==len(string):
            l=list(string)
            l[0],l[j]=l[j],l[0]
            print(''.join(i for i in l))

        elif len(string)%2==1 and k==len(string)-1:
            l=list(string)
            l[0],l[j]=l[j],l[0]
            print(''.join(i for i in l))

        else:
            print(string)
'''

#Romaji

string=input()
t=0

if string[len(string)-1]=='n' or string[len(string)-1]=='a' or string[len(string)-1]=='e' or string[len(string)-1]=='i' or string[len(string)-1]=='o' or string[len(string)-1]=='u':

    for i in range(0,len(string)-1,2):

        if (string[i]!='n' or string[i]!='a' or string[i]!='e' or string[i]!='i' or string[i]!='o' or string[i]!='u') and (string[i+1]=='a' or string[i+1]=='e' or string[i+1]=='i' or string[i+1]=='o' or string[i+1]=='u'):
            t=1
            
        elif (string[i]=='a' or string[i]=='e' or string[i]=='i' or string[i]=='o' or string[i]=='u') and string[i+1]=='a' or string[i+1]=='e' or string[i+1]=='i' or string[i+1]=='o' or string[i+1]=='u':
            t=1
            
        elif string[i]=='n':
            t=1

        elif string[i]=='a' or string[i]=='e' or string[i]=='i' or string[i]=='o' or string[i]=='u':
            t=1
            
        else:
            t=0
            break

else:
    t=0
        
if t==0:
    print('NO')
else:
    print("YES")





























        
            
        

        









