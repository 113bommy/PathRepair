n=int(input())
cnt=0

a,b,c=0,0,0
for i in range(n):
    s=input()
    cnt +=s.count("AB")
    if s[0]=="B" and s[-1]=="A":c +=1
    elif s[0]=="B":b +=1
    elif s[-1]=="A": a +=1

if a==0 and b==0:print(cnt+min(0,c-1))
else:print(cnt+min(a,b)+c)