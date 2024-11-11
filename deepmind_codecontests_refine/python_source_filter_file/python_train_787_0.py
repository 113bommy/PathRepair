s=input()#want small
t=input()#want large
n=len(s)
vs=[0]*26
vt=vs[:]

for i in range(n):
    vs[ord(s[i])-97]+=1
    vt[ord(t[i])-97]+=1
ns=n//2+n%2
nt=n//2
cur=0
starts=0
ends=0
for i in range(26):
    if cur+vs[i]<=ns:
        cur+=vs[i]
    else:
        vs[i]=ns-cur
        cur=ns
        ends=i
        break
cur=0
startt=0
endt=25
for i in range(25,-1,-1):
    if cur+vt[i]<=nt:
        cur+=vt[i]
    else:
        vt[i]=nt-cur
        cur=nt
        startt=i
        break
res=['*']*n
start=0
end=n-1
for i in range(n):
    while(starts<26 and vs[starts]==0): 
        starts+=1
    while(ends>=0 and vs[ends]==0): 
        ends-=1
    while(startt<26 and vt[startt]==0): 
        startt+=1
    while(endt>=0 and vt[endt]==0): 
        endt-=1
    while(res[start]!='*'):
        start+=1
    while res[end]!='*':
        end-=1
    if i%2==0:# s
        
        if starts>=endt:
            res[end]=chr(97+ends)
            vs[ends]-=1
        else:
            res[start]=chr(97+starts)
            vs[starts]-=1
    else:
        if endt<=starts:
            res[end]=chr(97+startt)
            vt[startt]-=1
        else:
            res[start]=chr(97+endt)
            vt[endt]-=1
            
for i in range(n):
    print(res[i],end='')            
        
    
