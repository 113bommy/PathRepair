n=int(input())
s=input()
ans,ans1=0,0
w=0
if s[n-1]==">":
    x=s[::-1]
    t=0
    # print(x,s)
    for  i in range (len(x)):
        if x[i]!=">":
            ans1=i
            t=1
            break
        elif (i==len(s)-1 and x[len(s)-1]==">" and t==0):
            ans1=i+1




if s[0] =="<" :
    f=0
    # print("hg")
    for i in range(len(s)) :
        if s[i] != "<":
            ans=i
            # print(i)
            f=1
            break
        elif(i==len(s)-1 and s[len(s)-1]=="<" and f==0 ):
            ans=i+1
elif (s[0]!="<" and s[len(s)-1]!=">"):
    print(0)
    w=1
if w==0:
    # print(ans)
    print(max(ans1,ans))