import math
n=int(input())
r0=0
b0=0
g0=0
r1=0
b1=0
g1=0
r2=0
b2=0
g2=0
s=input()
a=[]
b=[]
c=[]
for i in range(n):
     if(i%3==0):
          if(s[i]=='R'):
               r0+=1
          if(s[i]=='G'):
               g0+=1
          if(s[i]=='B'):
               b0+=1
     elif(i%3==1):
          if(s[i]=='R'):
               r1+=1
          if(s[i]=='G'):
               g1+=1
          if(s[i]=='B'):
               b1+=1
     else:
          if(s[i]=='R'):
               r2+=1
          if(s[i]=='G'):
               g2+=1
          if(s[i]=='B'):
               b2+=1
a.append(r0)
a.append(g0)
a.append(b0)
b.append(r1)
b.append(g1)
b.append(b1)
c.append(r2)
c.append(g2)
c.append(b2)
Max=0
maxi=0
maxj=0
maxk=0
for i in range(3):
     for j in range(3):
          for k in range(3):
               if(Max<(a[i]+b[j]+c[k]) and i!=j and j!=k and i!=k):
                    Max=a[i]+b[j]+c[k]
                    maxi=i
                    maxj=j
                    maxk=k
print((sum(a)+sum(b)+sum(c))-Max)
if(maxi==0):
     Res="R"
elif(maxi==1):
     Res="G"
elif(maxi==2):
     Res="B"
if(maxj==0):
     Res=Res+"R"
elif(maxj==1):
     Res=Res+"G"
elif(maxj==2):
     Res="B"
if(maxk==0):
     Res+="R"
elif(maxk==1):
     Res+="G"
elif(maxk==2):
     Res+="B"
print(Res*(math.floor(n/3))+Res[0:(n%3)])


