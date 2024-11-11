
import sys
#sys.stdin=open("data.txt")
input=sys.stdin.readline

n=int(input())
s=input().strip()

memo={}
def getans(a,b,c):
    while a and c and a[0]==c[-1]:
        a=a[1:]
        c=c[:-1]
    if b=="":
        if a=="" and c=="": return 1
        else: return 0
    key=a+"/"+b+"/"+c
    if key in memo: return memo[key]
    # select first letter
    ans=0
    for i in range(1,len(b)):
        if b[0]==b[i]:
            ans+=getans(a,b[1:i],b[i+1:]+c)
    # don't select first letter
    ans+=getans(a+b[0],b[1:],c)
    memo[key]=ans
    #print(key,ans)
    return ans

print(getans("",s,"")*2)

#print(len(memo))
