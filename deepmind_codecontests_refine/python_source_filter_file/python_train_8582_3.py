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
'''
string=input()
t=0

if string[len(string)-1]=='n' or string[len(string)-1]=='a' or string[len(string)-1]=='e' or string[len(string)-1]=='i' or string[len(string)-1]=='o' or string[len(string)-1]=='u':
    t=1
    for i in range(0,len(string)-1):

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

'''

#String Task
'''
string=input().lower()

l=['a','e','i','o','u','y']
k=list(string)
i=0

while i <len(k):
    if k[i] in l:
        k.pop(i)
    else:
        i+=1
        
for i in range(len(k)):
    
    print('.'+k[i],end="")
'''

#chat room
'''
string=input().lower()

if len(string)<5:
    print("NO")
else:
    l=['h','e','l','l','o']
    k=list(string)
    i=0
    
    while i<len(k):
        if k[i]==l[0]:
            l.pop(0)
            i+=1

        else:
            i+=1

        if len(l)==0:
            break

    if len(l)==0:
        print("YES")
    else:
        print("NO")

'''

#cAPS lOCK
'''
string=input()

a1=a=b=0
l=list(string)

if ord(l[0])<91:
    a1+=1
else:
    a1=0
    
for i in range(1,len(string)):

    if ord(l[i])<91:
        b+=1

if a1==0 and b==len(l)-1:
    for i in range(len(l)):
        if i==0:
            print(chr(ord(l[i])-32),end="")
        else:
            print(chr(ord(l[i])+32),end="")
        
elif a1==1 and b==len(l)-1:
    for i in range(len(l)):
        print(chr(ord(l[i])+32),end="")

else:
    print(string)
    
'''

#Lecture
'''
n,m=map(int,input().split())
q1=[]
q2=[]

for i in range(m):
    a,b=input().split()
    q1.append(a)
    q2.append(b)

k=input()

l=list(k.split())

for i in range(n):

    a=q1.index(l[i])
    if len(q1[a]) > len(q2[a]):
        print(q2[a],end=" ")
    else:
        print(q1[a],end=" ")
'''

# Football
'''
l=[1,0]

t=int(input())
string=input()

for i in range(1,t):

    n=input()
    if n==string:
        l[0]+=1
    else:
        j=n
        l[1]+=1

if l[0]>l[1]:
    print(string)

else:
    print(j)
'''

#Pangram
'''
n=int(input())

string=input().lower()
l=[0]*26

if n>=26:
    
    for i in range(n):
        l[ord(string[i])-97]+=1

    if min(l)!=0:
        print("YES")
    else:
        print("NO")

else:
    print("NO")
'''

#Amusing Joke
'''
s1=input().lower()
s2=input().lower()

string=input().lower()
l=[0]*26

for i in range(len(s1)):
    l[ord(s1[i])-97]+=1

for i in range(len(s2)):
    l[ord(s2[i])-97]+=1

t=0


for i in range(len(string)):

    if l[ord(string[i])-97]!=0:
#        print(string[i],l[ord(string[i])-97])
        l[ord(string[i])-97]-=1

    else:
        t=1
        break

if t==1:
    
    print("NO")
    
elif t==0 and max(l)==0:
    print("YES")

else:
    print("NO")

'''

#Night at the Museum
'''
string=input()

su=min(ord(string[0])-97 - 0 , 26 - ord(string[0])+97 -0)

for i in range(1,len(string)):
    if string[i-1]>string[i]:
        su+=min(abs( (ord(string[i])-97) - (ord(string[i-1])-97 ) ), abs(26+ (ord(string[i])-97 ) - (ord(string[i-1])-97) ))
    else:
        su+=min(abs( (ord(string[i])-97) - (ord(string[i-1])-97 ) ), abs(26- (ord(string[i])-97 ) +(ord(string[i-1])-97) ))

print(su)
'''

#Cards
'''
n=int(input())

string=input()
l=[0]*26
q=[]


for i in range(n):
    l[ord(string[i])-97]+=1

while max(l)!=0:
    if l[13]>=2 and l[8]>=1 and l[4]>=1:
        q.append(9)
        l[13]-=2
        l[8]-=1
        l[4]-=1

    elif l[4]>=1 and l[8]>=1 and l[6]>=1 and l[7]>=1 and l[19]>=1:
        q.append(8)
        l[4]-=1
        l[8]-=1
        l[6]-=1
        l[7]-=1
        l[19]-=1

    elif l[18]>=1 and l[4]>=2 and l[21]>=1 and l[13]>=1:
        q.append(7)
        l[18]-=1
        l[4]-=2
        l[21]-=1
        l[13]-=1

    elif l[18]>=1 and l[8]>=1 and l[23]>=1 :
        q.append(6)
        l[18]-=1
        l[8]-=1
        l[23]-=1

    elif l[5]>=1 and l[8]>=1 and l[21]>=1 and l[4]>=1:
        q.append(5)
        l[5]-=1
        l[8]-=1
        l[21]-=1
        l[4]-=1

    elif l[5]>=1 and l[14]>=1 and l[20]>=1 and l[17]>=1:
        q.append(4)
        l[5]-=1
        l[14]-=1
        l[20]-=1
        l[17]-=1
        
    elif l[19]>=1 and l[7]>=1 and l[17]>=1 and l[4]>=2:
        q.append(3)
        l[19]-=1
        l[7]-=1
        l[17]-=1
        l[4]-=2

    elif l[19]>=1 and l[22]>=1 and l[14]>=1:
        q.append(2)
        l[19]-=1
        l[22]-=1
        l[14]-=1

    elif l[14]>=1 and l[13]>=1 and l[14]>=1:
        q.append(1)
        l[14]-=1
        l[13]-=1
        l[4]-=1

    else:
        q.append(0)
        l[25]-=1
        l[4]-=1
        l[17]-=1
        l[14]-=1
        

q=sorted(q,reverse=True)
for i in range(len(q)):
    print(q[i],end=" ")

'''  

#Telephone Number
'''
for _ in range(int(input())):

    n=int(input())

    string=input()
    a=n-11
    t=0
    
    if a<0:
        t=1
        
    elif a==0 and string[0]!="8":
        t=1
        
    else:
        l=list(string)

        while l[0]!='8':
            if a==0 and l[0]!=8:
                t=1
                break
                
            l.pop(0)
            a-=1

    if t==1:
        print("NO")
    else:
        print("YES")
'''

#LLPS
'''
def subs(s):

    sub=[[]]

    for i in s:
        sub+=[lst + [i] for lst in sub]

    return sub

    
string=input()

f=subs(list(string))

q=[]

for i in range(len(f)):
    t=0
    for j in range(len(f[i])//2):
        
        if f[i][j]!=f[i][len(f[i])-j-1]:
            t=1
            break
    if t!=1:
        q.append(f[i])

max=q[0]
for i in range(1,len(q)):
    if max < q[i]:
        max=q[i]

print(''.join(i for i in max))
'''

#Haiku
'''
s1=input().strip()
s2=input().strip()
s3=input().strip()
count1=count2=count3=0

for i in range(len(s1)):
#    print(s1[i])
    if s1[i]=="a" or s1[i]=="e" or s1[i]=="i" or s1[i]=="u" or s1[i]=="o":

        count1+=1

for i in range(len(s2)):
    if s2[i]=="a" or s2[i]=="e" or s2[i]=="i"or s2[i]=="u"or s2[i]=="o":
        count2+=1


for i in range(len(s3)):
    if s3[i]=="a" or s3[i]=="e" or s3[i]=="i"or s3[i]=="u"or s3[i]=="o":
        count3+=1

    elif s3[i]==" ":
        continue

if count1==5 and count2==7 and count3==5:
    print("YES")
else:
    print("NO")

'''

# Help Far Away Kingdom
'''
n=input()
t=0

for i in range(len(n)):

    if n[i]=="." and n[i-1]!="9" and n[i+1]<"5":
        t=0
        break

    elif n[i]=="." and n[i-1]!="9" and n[i+1] >= "5" :
        t+=1
        break

    elif n[i]=="." and n[i-1]=="9" :
        t=-1
        break

l=[]

for i in range(len(n)):
    if n[i]==".":
        break
    else:
        l.append(int(n[i]))

if t==1:
    l[len(l)-1]+=1
    print(''.join(str(i) for i in l))

elif t==0:
    print(''.join(str(i) for i in l))

else:
    print("GOTO Vasilisa.")
'''

#Even But not even
'''
for _ in range(int(input())):

    n=int(input())
    string=input()
    su=t=k=0
    l=list(string)
    
    for i in range(len(string)):
        su+=int(string[i])
        
        if string[i]=='0' and i!=len(string)-1:
            l.pop(i-k)
            k+=1

    
    string1=''.join(i for i in l)
    k=0
#    print(string1)
    if int(string1)%2==1:

        if su%2==0:
            t=0

        else:
            for i in range(len(l)):
                if int(l[i])%2!=0 and i!=len(l[i]):
                    l.pop(i)
                    break

            t=1

    else:

        if su%2==0:
            for i in range(len(l)-1,-1,-1):
                l.pop(i-k)
                k+=1
                
                if len(l)!=0 and int(l[len(l)-1])%2==1 :
                    break
            t=1

        else:
            for i in range(len(l)-1,-1,-1):
                l.pop(i-k)
                k+=1
                
                if len(l)!=0 and int(l[len(l)-1])%2==1:
                    break

            for i in range(len(l)):
                if int(l[i])%2==1 and i!=len(l[i]):
                    l.pop(i)
                    break
            t=1
#    print(l)
    if len(l)!=0:
        if t==1:
            print(''.join(i for i in l))

        else:
            print(string)
    else:
        print('-1')

'''

#Motarack's Birthday
'''
import math

for _ in range(int(input())):

    n=int(input())

    l=list(map(int,input().split()))

    l1=[]
    lmax=[]
#    lindex=[]
    lneg=[]

    for i in range(n):
        if l[i]!=-1:
            l1.append(l[i])
#            lindex.append(i)

        else:
            lneg.append(i)

        if i!=n-1 :
            if (l[i]!=-1 and l[i+1]!=-1):
                lmax.append(abs(l[i]-l[i+1]))

#    print(lmax)
    ma1=ma2=0
    k=set()
    for i in range(len(lneg)):
        if lneg[i]-1>=0 and l[lneg[i]-1]!=-1:
            k.add(lneg[i]-1)

        if lneg[i]+1<n and l[lneg[i]+1]!=-1:
            k.add(lneg[i]+1)

#    print(k)
    su=0
    k=list(k)

    if len(k)>=2:
        for i in range(len(k)):
            su+=l[k[i]]
#        print(su)

        avg1=math.ceil(su/len(k))

        for i in range(len(k)):
            ma1=max(ma1 , abs(avg1-l[k[i]]) )
#            print(ma)

        avg2=math.floor(su/len(k))

        for i in range(len(k)):
            ma2=max(ma2, abs(avg2-l[k[i]] ))

        ma=min(ma1,ma2)
        if ma==ma1:
            avg=avg1

        else:
            avg=avg2

    elif len(k)==0:
        ma=0
        avg=1

    elif len(k)==1:
        ma=0
        avg=l[k[0]]

    for i in range(len(lmax)):
#        print(i)
        if lmax[i] > ma:
            ma=lmax[i]

    print(ma,avg)

'''

# Motarack's Birthday
'''
import math

for _ in range(int(input())):

    n=int(input())

    l=list(map(int,input().split()))
    k=list(l)
    l1=set()
    
    for i in range(n):
        if l[i]==-1 :
            if( i-1>=0 and l[i-1]!=-1):
                
                l1.add(l[i-1])

            if (i+1 < n and l[i+1]!=-1):
                l1.add(l[i+1])

    l1=list(l1)
    if len(l1)>=2:

        l1.sort()
        ma=l1[0]
        mi=l1[len(l1)-1]

        avg=(ma+mi)//2

        for i in range(n):
            if l[i]==-1:
                l[i]=avg

        ma=0
        for i in range(1,n):
            if ma < abs(l[i]-l[i-1]):
                ma=abs(l[i]-l[i-1])

        print(ma,avg)
        
    elif len(l1)==1:
        ma=0
        for i in range(n):
            if l[i]==-1:
                l[i]=l1[0]
        for i in range(1,n):
            if ma<abs(l[i]-l[i-1]):
                ma=abs(l[i]-l[i-1])
        print(ma,l1[0])

    elif len(l1)==0:
        print("0","1")

'''

#Ayoub's function
'''
for _ in range(int(input())):

    n1,m1=input().split()
    n=int(n1)
    m=int(m1)
    
    zeroes=n-m

    groups=m+1
    
    k=zeroes//groups

    substr=(n*(n+1))//2

    zerostr=(k*(k+1))//2

    ans = substr-zerostr * groups - (k+1)*(zeroes % groups) 

    print(ans)

'''

#Fight with monsters
'''
import math

n,a,b,k=map(int,input().split())

l=list(map(int,input().split()))

count=0

for i in range(n):
    if l[i]%(a+b) != 0:
        l[i]=l[i]%(a+b)

    else:
        j=l[i]//(a+b)
        l[i]-=(a+b)*(j-1)

print(l)
i=0
while i<len(l):
    if l[i]<=a:
        count+=1
        l.pop(i)
        
    else:
        l[i]-=a
        i+=1

print(l,count)
#l.sort()

for j in range(k):
    i=l.index(min(l))
    if l[i]<=a:
        count+=1
        l.pop(i)
            
    else:
        l[i]-=a
      
print(l)
print(count)

'''    
    
#Strings coloring(easy version)
'''
n=int(input())

string=input()
l=[]
a1='a'
b1='a'
t=0

for i in range(n):
    if string[i]>=a1:
        l.append(0)
        a1=string[i]

    elif string[i]>=b1:
        l.append(1)
        b1=string[i]

    else:
        t=1
        break
            
if t==1:
    print("NO")

else:
    print("YES")
    for i in range(n):
        print(l[i],end="")
'''

#Strings coloring(hard version)
'''
n=int(input())

s=input()
k=[i for i in range(1,27)]
l=[]
a='a'

count=count1=1

for i in range(n):
    if s[i]>=a:
        l.append(ord(s[i])-96)
        a=s[i]

    else:
        l.append(ord(s[i])-96)

mxx=l[0]

for i in range(n):
    if l[i]>mxx:
        +

'''

#Time to Run
'''
import math
n,m,k=map(int,input().split())

x=4*n*m
y=2*n
z=2*m
n-=1
m-=1

if x-y-z < k:
    print("NO")


else:
    ans=[]
    if not m:
        ans.append([min(k,n),'D'])
        k-=min(k,n)

        if k:
            ans.append([min(k,n),'U'])

        if k:
            print("NO")
            exit(0)

    if k:
        if k:
            ans.append([min(k,m),'R'])
            k-=min(k,m)

        if k:
            ans.append([min(k,m),'L'])
            k-=min(k,m)

    nn=n
    while(min(k,nn)):
        if len(ans)>3000:
            break

        l=0

        if k:
            ans.append([1,'D'])
            k-=1

        if k:
            ans.append([min(k,m),'R'])
            k-=min(k,m)

        if k:
            if min(k//3,m):
                ans.append([min((k//3),m),'UDL'])
                l=m-min((k//3),m)
                k-=min((k//3)*3,m*3)

            else:
                l=k

        if k<3 and k>0 and l:
            ans.append([min(k,l,m),'L'])
            k-=min(k,l,m)

    if k:
        ans.append([min(k,n),"U"])
        k-=min(k,n)

    if((not k) and (len(ans)<3001)):
        print("YES")
        print(len(ans))
        for i in range(len(ans)):
            print(ans[i][0],ans[i][1])

    else:
        print("NO")
'''

#aerodynamic
'''
n=n=int(input())

x=[0]*(n+2)
y=[0]*(n+2)

for i in range(n):
    x[i],y[i]=map(int,input().split())

if (n&1):
    print("NO")
    exit(0)

for i in range(n//2):
    if x[0] + x[n//2]!= x[i]+x[i+n//2] or y[0]+y[n//2] != y[i]+y[i+n//2] :
        print("NO")
        exit(0)

print("YES")
            
'''

#Element extermination
'''
for _ in range(int(input())):

    n=int(input())
    l=list(map(int,input().split()))

    if l[0] <l[len(l)-1]:
        print("YES")
    else:
        print("NO")
'''

#neighbour grid
'''
def valid(l,i,j,n,k):

    m=l[i][j]

    t=c=0
    
    if i>=0 and i<n and j>=0 and j<k:
    
        if i-1>=0 :
            c+=1

        if i+1<n :
    
            c+=1
        if j-1 >=0 :
    
            c+=1
        if j+1<k:
            c+=1

        
        if c > m:
            c=0
            
            if i-1>=0 and l[i-1][j]==0:
                l[i-1][j]+=1
                c+=1
                
                if i-2>=0 and l[i-2][j]>0:
                    l[i-2][j]+=1
                    l[i-1][j]+=1
                    
                elif j-1 >=0 and l[i-1][j-1]>0 :
                    l[i-1][j-1]+=1
                    l[i-1][j]+=1
                    
                elif j+1 < k and l[i-1][j+1]>0 :
                    l[i+1][j+1]+=1
                    l[i-1][j]+=1
                    
            if i+1 < n and l[i+1][j]==0 and c<m:

                l[i+1][j]+=1
                c+=1
                                
                if i+2<n and l[i+2][j]==0 :
                    l[i+2][j]+=1
                    l[i+1][j]+=1
                    
                elif j-1 >=0 and l[i][j-1]>0 :
                    l[i+1][j-1]+=1
                    l[i+1][j]+=1
                    
                elif j+1<k and l[i][j+1]>0 :
                    l[i+1][j+1]+=1
                    l[i+1][j]+=1
                
                
            if j-1 >=0 and l[i][j-1]>0 and c<m:
                l[i][j-1]+=1
                c+=1

                if j-2 >=0 and l[i][j-2]>0 :
                    l[i][j-2]+=1
                    l[i][j-1]+=1
                    
                if i-1>=0 and l[i-1][j-1]>0:
                    l[i-1][j-1]+=1
                    l[i][j-1]+=1
                
                if i+1<n and l[i+1][j-1]==0 :
                    l[i+1][j-1]+=1
                    l[i][j-1]+=1                
                
            if j+1<k and l[i][j+1]>0 and c<m:
                l[i][j+1]+=1
                c+=1

                if j+2 >=0 and l[i][j+2]>0 :
                    l[i][j+2]+=1
                    l[i][j+1]+=1
                    
                if i-1>=0 and l[i-1][j+1]>0:
                    l[i-1][j+1]+=1
                    l[i][j+1]+=1
                
                if i+1<n and l[i+1][j+1]>0 :
                    l[i+1][j+1]+=1
                    l[i][j+1]+=1

            return True
        
        else:
            return False


for _ in range(int(input())):

    n,m=map(int,input().split())

    l=[list(map(int,input().split()))for i in range(n)]

    t=1
    for i in range(n):
        for j in range(m):
            if l[i][j]>0:
                if valid(l,i,j,n,m):
                    t=1

                else:
                    t=0

    if t==1:
        print("YES")

        for i in range(n):
            for j in range(m):
                print(l[i][j],end=" ")
            print()

    else:
        print("NO")
                    
'''

#Sign Flipping
'''
for _ in range(int(input())):
    n=int(input())

    l=list(map(int,input().split()))

    for i in range(n):
        if (i+1)%2==0 and l[i]>0:
            l[i]=-l[i]

        if (i+1)%2==1 and l[i]<0:
            l[i]=-l[i]

    for i in range(n):
        print(l[i],end=" ")
            
'''         
                
#obtain the string
'''
from collections import defaultdict

for _ in range(int(input())):

    s=input()
    t=input()

    x=defaultdict(list)

    if s==t:
        print("1")
    else:
        z=1
        flag=0
        for i in range(len(s)):
            x[s[i]].append(i)

        pointer=-1

        
        for i in range(len(t)):
            m=0

            if len(x[t[i]])==0:
                flag=1
                break
           
            for edges in x[t[i]]:
                if edges > pointer:
                    pointer=edges
                    m=0

                    break
                           
                else:
                    m=1
                    
            if m==1:

                pointer=x[t[i]][0]
                z+=1

        if flag==1:
            print("-1")

        else:
            print(z)
'''

#Infinite prefixes
'''
for _ in range(int(input())):

    n,x=map(int,input().split())

    s=input()
    zeroes=0
    ones=0
    
    for i in range(n):
        if s[i]=='0':
            zeroes+=1
        else:
            ones+=1

    k=zeroes-ones

    if k<0 and x>0:
        print("0")

    elif k>0 and x<0:
        print("0")

    elif (k==1 or k==-1) and x==0:
        print("1")
    elif k==0 and x==0:
        print("-1")
        
    else:
        j=1
        t=x
        if k>0:
            q=x//k
            z=''

            z+=s
            z*=q+1
            
            for i in range((q*n)-1 , (q-1)*n , -1):
#                print(i,(q-1)*n,(q*n)-1)
                if z[i]=='1':
                    t-=1
                else:
                    t+=1

                if t==x:
#                    print(i)
                    j+=1

            t=x
            
            for i in range((q*n),(q+1)*n):
#                print(x,i)
                if z[i]=='1':
                    t-=1
                else:
                    t+=1

                if t==x:
#                    print(i)
                    j+=1
                    
            print(j)
            
        else:
            k=abs(k)
            x=abs(x)
            q=x//k

            z=''
            
            z+=s
            z*=q

            for i in range((q*n)-1,(q-1)*n,-1):
                if z[i]=='1':
                    t+=1
                else:
                    t-=1

                if t==x:
                    j+=1

            t=x
            for i in range(q*n , (q-1)*n):
                if z[i]=='1':
                    t+=1
                else:
                    t-=1

                if t==x:
                    j+=1
                    
            print(j)
'''

#Omkar and copletion
'''
for _ in range(int(input())):

    n=int(input())

    if n<500:
        for i in range(1,2*n,2):
            print(i,end=" ")
    else:
        for i in range(n):
            print("1",end=" ")
    print()

'''

#omkar and last class of math
'''
import math

def primes(n):

    t=n
    l=set()
    j=set()
    
    k=int(math.sqrt(n))+1
    while n%2==0:
        n=n//2
        l.add(2)
        j.add(n//2)
        
    for i in range(3,k,2):

        while n%i==0:
            
            l.add(i)
            j.add(n//i)
            n=n//i

    j=list(j)
            
    if len(l)!=0:
        return j

    else:
        return [n-1]

def gcd(a,b):

    if a==0:
        return b
    
    return gcd(b%a,a)
    
for _ in range(int(input())):
    n=int(input())

    if n%2==0:
        print(n//2,n//2)

    else:
        k=primes(n)
             
        for i in range(len(k)):
            t=gcd(n-k[i],k[i])
            if i==0:
                mi=t
            else:
                mi=max(mi,t)
                
        print(mi,n-mi)

'''

#omkar and baseball
'''
for _ in range(int(input())):

    n=int(input())
    l=list(map(int,input().split()))
    t=0
    
    for i in range(n-1,-1,-1):
        if l[i]==i+1:
            continue
        else:
            t=i
            break

    if t==0:
        print("0")

    else:
        j=[]
        for i in range(t,-1,-1):
            if l[i]==i+1:
               j.append(i+1)

        a=False
        
        for i in range(len(j)-1,-1,-1):
            if j[i]!=len(j)-i:
                a=True
                break

        if a==False:
            print("1")
        else:
            print("2")
            
'''

#Product of three numbers
'''
import math

def factor(n,a):

    l=[]
    r=n
    k=int(math.sqrt(n))+1

    d=1
    
    while n%(2**d)==0:
        if 2**d!=a and r//(2**d)!=a and r//(2**d)!=2**d and 2**d!=r:
            l.append(2**d)
            l.append(r//2**d)
            
            n//=2**d
            d+=1
            break
        
        else:
            d+=1


    for i in range(3,k,2):
        d=1
        while n%(i**d)==0:
            if i**d!=a and r//(i**d)!=a and r//(i**d)!=i**d and i**d!=n:
                l.append(i**d)
                
                l.append(r//i**d)
                n//=i**d
                d+=1
                break
            else:
                d+=1

    return l

def factors(n):

    l=[]
    r=n
    k=int(math.sqrt(n))+1

    d=1
    while n%2==0:
        l.append(2**d)
        d+=1

        n//=2

    for i in range(3,k,2):
        d=1
        while n%i==0:
            l.append(i**d)
            d+=1
            
            n//=i

    if n==1:
        return l
    else:
        l.append(n)
        return l
    
for _ in range(int(input())):

    n=int(input())

    l=factors(n)

    if len(l)<3:
        print("NO")

    else:
        t=x=y=z=0
        for i in range(len(l)):
            a=n//l[i]
            
            f=factor(a,l[i])
            if len(f)>1:
                x=f[0]
                y=f[1]
                z=l[i]
                t=1
                break

        if t==1:
            print("YES")
            print(z,x,y)

        else:
            print("NO")

'''
            
#MEx maximizing
'''
l=[0]*(pow(10,6)+7)

q,x=map(int,input().split())

for _ in range(q):

    n=int(input())
    w=0

    if n < pow(10,6):

        if l[n]==0:
            l[n]+=1

            for i in range((n//x),-1,-1):
                if l[n-(x*i)]==0:
                    w=n-(x*i)
                    break
            
            if w!=0:
                l[n]=0
                l[w]=1

        else:
            i=2
            while l[n+x]!=0:
                x=x*i
                i+=1

            l[n+x]+=1

    else:
        for i in range(n//x,-1,-1):
            if l[n-(x*i)]==0:
                w=n-(x*i)
                break

        if w!=0:
            l[w]+=1

    i=0

    while l[i]!=0:
        i+=1

    print(i)

'''
#correct sol
'''
q,x=input().split()
q=int(q)
x=int(x)

count=[0]*x
for _ in range(q):
    n=int(input())

    a=n%x

    count[a]+=1

    j=min(count)

    for i in range(x):
        if j==count[0]:
            print(count[0]*x)
            break
        elif j==count[i]:
            print((count[i]*x)+i)
            break
'''

#omkar and circle
'''
n=int(input())
l=list(map(int,input().split()))

pre=[0]*n
suf=[0]*n

for i in range(n):
    pre[i]=l[i]
    if i>=2:
        pre[i]+=l[i-2]


for i in range(n-1,-1,-1):
    suf[i]=l[i]
    if n-i>2:
        suf[i]+=l[i+2]

ans=0

ans=max(ans,suf[]+pre[-])
print(ans)

'''

#Three indices
'''
for _ in range(int(input())):

    n=int(input())

    l=list(map(int,input().split()))
    x=y=z=t=0

    for i in range(n-2):
        if l[i] < l[i+1] and l[i+2]<l[i+1] :
            x=i+1
            y=i+2
            z=i+3
            t=1
            break

    if t==1:
        print("YES")
        print(x,y,z)

    else:
        print("NO")

'''

#One bomb
#test case 53 dikkat kr rha hai
'''
n,m=map(int,input().split())

l=[input() for i in range(n)]

v=[0]*n  #rows
g=[0]*m  #column
cnt=0
k=[]

for i in range(n):
    for j in range(m):
        if l[i][j]=="*":
            cnt+=1
            v[i]+=1
            g[j]+=1
            k.append([j,i])

t=cnt
print(g)
print(v)

a=g.index(max(g))
b=v.index(max(v))

print(a,b,len(k),k)

i=0
while i<len(k):
    if k[i][0]==a or k[i][1]==b:
          k.pop(i)
    else:
        i+=1
        break

if len(k)==0:
    print("YES")
    print(b+1,a+1)

else:
    print("NO")

'''

#Distance in Tree

'''
from collections import defaultdict

class graph:

    def __init__(self,v):
        self.vertex=v
        self.graph=defaultdict(list)

    def add(self,u,v):
        self.graph[u].append(v)

    def count(self,k,s):
        visited=[False]*(self.vertex+1)
        p=[0]
        
        g.dfsutil(visited,s,0,0,p)

        return p[0]

    def dfsutil(self,visited,s,cnt,t,p,k):

        visited[s]=True
        if t>k-1:
            p[0]+=1
            
        for edges in self.graph[s]:
            cnt+=1
            if visited[edges]:
                continue

            if cnt>:
                p[0]+=1

            g.dfsutil(visited,edges,cnt-1,t+1,p)

n,k=map(int,input().split())
g=graph(n)

for i in range(n-1):
    a,b=map(int,input().split())
    g.add(a,b)

print(g.count(k,1))

'''

#EEvee

n=int(input())

s=input()

lno=[]
lname=['vaporeon','jolteon', 'flareon', 'espeon', 'umbreon', 'leafeon', 'glaceon', 'sylveon']

for i in range(n):
    lno.append(len(lname[i]))
    
#print(lno)
i=0
while i<len(lno):
    if lno[i]!=n:
        lno.pop(i)
        lname.pop(i)

    else:
#        print("hey")
        for j in range(n):
            if s[j]!="." and s[j]!=lname[i][j]:
#                print("why",s[j],lname[i][j])
                lno.pop(i)
                lname.pop(i)
                t=0
                break
            else:
##                print("what")
                t=1

        if t==1:
            print(lname[i])
            break
            



















