from sys import stdin
def kmp(pat, txt):
    leng = 0;i = 1
    ans=0
    M = len(pat) ;N = len(txt) ;lps = [0]*M ;j = 0
    #Calculo de lps, prefifo propio mas largo que tambien es sufijo de pat[0:i]
    while i < M:
        if pat[i]== pat[leng]:
            leng += 1
            lps[i] = leng
            i += 1
        elif leng != 0:
            leng = lps[leng-1] 
        else:
            lps[i] = 0
            i += 1
    i = 0 
    while i < N:

        if pat[j] == txt[i]: 
            i += 1;j += 1  
        if j == M:
            if ((i-j)==0 or txt[i-j-1]==" ") and ((i-j+len(pat))==(len(txt)) or txt[i-j+len(pat)]==" "):
                ans+=1
                i=i-j+len(pat)
                j =0
            else:
                j = lps[j-1] 
        elif i < N and pat[j] != txt[i]: 
            if j != 0: 
                j = lps[j-1] 
            else: 
                i += 1
    return ans
n=int(stdin.readline().strip())
s1=stdin.readline().strip().split()
s=[]
x=1
d=dict()
d1=dict()
st=set()
ans=n-1
s2=""
for i in s1:
    ans+=len(i)
    if i not in st:
        d.update({i:x})
        d1.update({x:len(i)})
        x+=1
        st.add(i)
    s.append(d[i])
    s2+=str(d[i])
    if len(s)<n:
        s2+=" "
acum=0
s3=s2.split()
tot=ans
for i in range(n):
    x=0
    y=0
    for j in range(i,n):
        x+=(d1[s[j]]-1)
        y+=len(s3[j])
        z=kmp(s2[acum:acum+y+j-i],s2)
        if z>1:
            aux=tot-(2*(x+j-i))
            #print(s2[acum:acum+y+j-i],"/ ",aux,acum,y,j-i)
            if aux<ans:
                #print(s2[acum:acum+y+j-i+1],"/ ",aux)
                ans=aux
    acum+=len(s3[i])+1
print(ans)
