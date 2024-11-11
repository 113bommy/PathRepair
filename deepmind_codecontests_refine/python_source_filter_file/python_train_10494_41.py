n,a,b,c,d=map(int,input().split())
s=input()
if("##" in s[a:max(c,d)]):
    print("No")
elif(c<d):
    print("Yes")
elif("..." in s[b:d+1]):
    print("Yes")
else:
    print("No")
