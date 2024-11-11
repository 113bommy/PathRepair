"Educational Codeforces Round 89 (Rated for Div. 2)"
"A. Shovels and Swords"
# y=int(input())
# ans=[]
# for i in range(y):
#     al=input().split()
#     m = list(map(int, al))
#     a=min(m[0],m[1])
#     b=max(m[0],m[1])
#     d=int((b+a)/3)
#     t=0
#     t=min(d,a,b)
#     ans.append(t)
# for i in ans:
#     print(i)   
"B. Shuffle"
# y=int(input())
# ans=[]
# for i in range(y):
#     al=input().split()
#     m = list(map(int, al))
#     n=m[0]
#     x=m[1]
#     s=m[2]
#     a=x
#     b=x
#     for j in range(s):
#         al=input().split()
#         m = list(map(int, al))
#         l=m[0]
#         r=m[1]
#         if a!=b:
#             #print(a,b,l,r,"if",l<=b,a<=r,l!=r,((l<=b or a<=r) and l!=r))
#             if l!=r and((l<=b and b<=r) or (l<=a and a<=r)):
#                 a=min(a,l)
#                 b=max(b,r)
    
#         else:
#             #print(a,b,l,r,"else",l<=b,a<=r,l!=r,((l<=b and a<=r) and l!=r))
#             if ((l<=b and a<=r) and l!=r):
#                 a=l
#                 b=r
#         #print(a,b,l,r,"-----")                
#     ans.append(b-a+1)        
# for i in ans:
#     print(i) 
"C. Palindromic Paths"
y=int(input())
ans=[]
for i in range(y):
    al=input().split()
    m = list(map(int, al))
    a=m[0]
    b=m[1]
    q=[]
    f=0
    if a%2!=b%2:
        f=1
    d=int((b+a-1)/2)    
    for j in range(a):
        al=input().split()
        m = list(map(int, al))
        q.append(m)
    t=0  
    t1=0
    z=min(a,b)
    x=max(a,b)
    r=[]
    r.append([0]*(a+b-1))
    r.append([0]*(a+b-1))
    for j in range(a):
        for k in range(b):
            if q[j][k]!=q[a-1-j][b-1-k]:
                t+=1 
            if q[j][k]==1:
                r[1][j+k]+=1
            else:
                r[0][j+k]+=1    
    print(r)
    l=int((a+b-1)/2)
    print("l=",l)
    for j in range(l):
        t1+=min(r[0][j]+r[0][a+b-2-j],r[1][j]+r[1][a+b-2-j])
    ans.append(int(t1))            
for i in ans:
    print(i) 