"Codeforces Round #260 (Div. 1)"
"A. Boredom"
# def Boredom():
#     y=int(input())
#     a=list(map(int,input().split()))
#     d={}
#     for i in a:
#         d.setdefault(i,0)
#         d[i]+=1
#     # print(d)    
#     k=list(d.keys())
#     k.sort()
#     # print(k)
#     l=len(k)
#     k.append(0)
#     d[0]=0
#     sum=0
#     if l==1:
#         print(k[0]*d[k[0]])
#         return
#     z=x=0
#     za=0    
#     for i in range(l):
#         # print(sum,z,x,k[i])
#         z+=(1-za)*d[k[i]]*k[i]
#         x+=za*(d[k[i]])*k[i]
#         za=1-za
#         if k[i]+1!=k[i+1]: 
#             sum+=max(z,x)
#             z=x=0
#     print(sum)
#     return             
       

# Boredom()
"Codeforces Round #321 (Div. 2)"
"B. Kefa and Company"
def Kefa_and_Company():
    n,dd=map(int,input().split())
    d={}
    for i in range(n):
        z,x=map(int,input().split())
        d.setdefault(z,0)
        d[z]+=x
    m=list(d.keys())
    m.sort()
    f=[0]
    for i in m:
        f.append(f[-1]+d[i])
    f.pop(0)
    # print(m)
    # print(f)
    i=j=0
    ans=[]
    l=len(m)
    while True:
        # print(i,j,m[i],m[j],ans)   
        if m[j]-m[i]>dd:
            if i==0:
                ans.append(f[j-1])
            # elif j==l-1:
            #     if m[j]-m[i-1]>dd:
            #         ans.append(f[j]-f[i-1]) 
            #     else           
            else:
                ans.append(f[j-1]-f[i-1]) 
            i+=1
        else:
            if j==l-1:
                if i==0:
                    ans.append(f[j])
                elif i==l-1:
                    ans.append(f[j]-f[i-1])
                else:
                    ans.append(f[j]-f[i-1])                        
                break
            j+=1
    ws=max(ans)
    print(ws)
    return
Kefa_and_Company()