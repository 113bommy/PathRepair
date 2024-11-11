"""n1,n2,k1,k2 = map(int,input().split())
flag1 = 0
flag2 = 0
i=1
while True:
    if i%2!=0:
        if n1 < 1:
            flag1=1
            break
        else:
            n1 -=1
            if n1<1:
                flag1=1
                break
    else:
        if n2 < 1:
            flag2=1
            break
        else:
            n2-=1
            if n2 < 1:
                flag2=1
                break
    i+=1
if flag1==1:
    print("Second")
else:
    print("First")"""

"""numbers = int(input())
seq = list(map(int,input().split()))
myArray = []
staircase = 0
i=0
myMap= dict()
while i<len(seq):
    if seq[i]==1:
        if myMap.get(1)==None:
            myMap[1]=1
        else:
            myMap[1]+=1
    i+=1
staircase = myMap[1]
i=0
j=i+1
while j<len(seq):
    if seq[i]==seq[j]:
        myArray.append(j-i)
        i=j
    j+=1
myArray.append(seq[j-1])
print(staircase)
for i in range(len(myArray)):
    print(myArray[i],end=" ")"""
"""testcases = int(input())
while testcases > 0:
    myMap = dict()
    length = int(input())
    myArray = list(map(int,input().split()))
    i=0
    j=i+1
    total=0
    while j<len(myArray):
        if j<=len(myArray)-2 and myArray[i]!=myArray[j] and myArray[i]+myArray[j]!=myArray[j+1]:
            total=myArray[i]+myArray[j]
            myArray.pop(j)
            myArray[i]=total
            i=0
            j=i+1
        elif j==len(myArray)-1 and myArray[i]!=myArray[j]:
            total = myArray[i]+myArray[j]
            myArray.pop(j)
            myArray[i]=total
            i=0
            j+=1
        else:
            i+=1
            j+=1
    print(len(myArray))
    testcases-=1"""
"""def isSubsetSum(set, n, sum):
	subset =([[False for i in range(sum + 1)] 
			for i in range(n + 1)])
	for i in range(n + 1):
		subset[i][0] = True
	for i in range(1, sum + 1):
		subset[0][i]= False
	for i in range(1, n + 1):
		for j in range(1, sum + 1):
			if j<set[i-1]:
				subset[i][j] = subset[i-1][j]
			if j>= set[i-1]:
				subset[i][j] = (subset[i-1][j] or
								subset[i - 1][j-set[i-1]])
	
	
	return subset[n][sum]
		
set = list(map(int,input().split()))
sum=0
for i in range(len(set)):
    sum+=set[i]
if sum%2!=0:
    print("NO")
else:
    sum=int(sum/2)
    n = len(set)
    if (isSubsetSum(set, n, sum) == True):
        print("YES")
    else:
        print("NO")"""

"""testcases = int(input())
while testcases > 0:
    n,x,a,b = map(int,input().split())
    if x==0:
        print(abs(a-b))
    else:
        if a==n and b==1 or b==n and a==1:
            print(abs(a-b))
        elif a==n and b!=1:
            while b>1 and x>0:
                b-=1
                x-=1
            print(abs(a-b))
        elif b==n and a!=1:
            while a>1 and x>0:
                a-=1
                x-=1
            print(abs(a-b))
        else:
            if b>a:
                while b<n and x>0:
                    b+=1
                    x-=1
                while a>1 and x>0:
                    a-=1
                    x-=1
                print(abs(b-a))
            else:
                while a<n and x>0:
                    a+=1
                    x-=1
                while b>1 and x>0:
                    b-=1
                    x-=1
                print(abs(a-b))
    testcases-=1"""

"""n,c = map(int,input().split())
myArray = list(map(int,input().split()))
word = 1
for i in range(1,len(myArray)):
    if myArray[i] - myArray[i-1]<=c:
        word+=1
    else:
        word=1
print(word)"""

"""testcases = int(input())
while testcases > 0:
    l1,r1,l2,r2 = map(int,input().split())
    a=l1
    b=-1
    i=l1
    while i<=r2:
        if i!=a:
            b=i
            break
        i+=1
    print(str(a)+" "+str(b))
    testcases-=1"""

a,b = map(int,input().split())
finalFlag=0
for i in range(a+1,b):
    c=str(i)
    myMap=dict()
    flag=0
    for i in range(len(c)):
        if myMap.get(c[i])==None:
            myMap[c[i]]=1
        else:
            flag=1
            break
    if flag==0:
        print(c)
        finalFlag=1
        break
if finalFlag==0:
    print(-1)
    
    
            
                
		


    
            
    
