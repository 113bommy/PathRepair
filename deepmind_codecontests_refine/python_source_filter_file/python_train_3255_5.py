import sys
# sys.setrecursionlimit(10**6) 
input=sys.stdin.readline
t=int(input())
# def  f(n):
#     z=int(n**0.5)+1
#     arr=[]
#     for i in range(1,z):
#         if(n%i==0):
#             arr.append(i)
#         while(n%i==0):
#             n=n//i
#     if(n!=1):
#         arr.append(n)
# def find(k):
# 	if(d[k]==k):
# 		return d
# 	else:
# 		return find(d[k])

# def union(rank,a,b):
# 	x = find(a)
# 	y = find(b)
# 	if(x!=y):
		

		

#         if rank[x] < rank[y]: 
            
#             d[x]=y
#             rank[y]+=1

#             # size[x]+=1
#         elif rank[y] > rank[x]: 
#             d[y]=x
#             rank[x]+=1
            
            


#         else : 
#             d[y]=x
#             rank[x]+=1
		

def gcd(a,b): 
      
   
    if (b == 0): 
         return a 
    return gcd(b, a%b) 
for t1 in range(t):
    n=int(input())
    l=list(map(int,input().split(" ")))
    

    x=sorted(l)
    j=0 
    pos={}
    for i in range(n):
        pos[l[i]]=[]
    for i in range(n):
        pos[l[i]].append(i)
    f=0
    z=min(l)
    for i in range(n):
        if(x[i]!=l[i]):
            if(gcd(x[i],l[i])!=z):
                f=1
                break
            else:
                al=pos[x[i]][-1]
                pos[x[i]].pop()
                l[i],l[al]=l[al],l[i]

    if(f==0):
        print("YES")
    else:
        print("NO")

            
    






