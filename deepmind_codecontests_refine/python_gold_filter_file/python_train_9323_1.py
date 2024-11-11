"Codeforces Round #384 (Div. 2)"
"C. Vladik and fractions"
# y=int(input())
# a=y
# b=a+1
# c=y*b
# if y==1:
#     print(-1)
# else:    
#     print(a,b,c)
"Technocup 2017 - Elimination Round 2"
"D. Sea Battle"
n,a,b,k=map(int,input().split())
s=list(input())
n=len(s)
lz=[]
zeros=[]
indexes=[]
flage=0
if s[0]=="0":
    lz.append(0)
    flage=1  
for i in range(1,n):
    if flage==1 and s[i]=="1":
        zeros.append(i-1-(lz[-1])+1)
        lz.append(i-1)
        flage=0
    elif flage==0 and s[i]=="0":
        lz.append(i)
        flage=1   

if s[-1]=="0":
    zeros.append(n-1-(lz[-1])+1)
    lz.append(n-1)
min_no_spaces=(a-1)*b
spaces_left=n-k    
l=len(lz)    
# print(lz)
# print(zeros)  
shotes=0
for i in range(len(zeros)):
    h=i*2
    if min_no_spaces!=0:
        # print(min_no_spaces)
        if min_no_spaces>=zeros[i]:
            min_no_spaces-=(int(zeros[i]/b))*b
        elif min_no_spaces<zeros[i]:
            shotes+=int((zeros[i]-min_no_spaces)/b)
            for j in range(int((zeros[i]-min_no_spaces)/b)):
                indexes.append(lz[h]+((j+1)*b))
            min_no_spaces=0    
    elif min_no_spaces==0:
        # print(min_no_spaces)
        shotes+=int(zeros[i]/b)
        for j in range(int(zeros[i]/b)):
            indexes.append(lz[h]+((j+1)*b))
print(shotes)
for i in indexes:
    print(i," ",end="",sep="")