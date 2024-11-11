def ii(): return int(input())
def fi(): return float(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi()) 

s=si()
t=si()
c=d=0
for i in range(0,len(s)-1,2):
    if s[i]=="8":
        if t[i]=="[":
            c+=1 
        elif t[i]=="(":
            d+=1 
    elif s[i]=="(":
        if t[i]=="8":
            c+=1 
        elif t[i]=="[":
            d+=1 
    else:
        if t[i]=="[":
            c+=1 
        elif t[i]=="8":
            d+=1 
if c>d:
    print("TEAM 1 WINS")
elif d>c:
    print("TEAM 2 WINS")
else:
    print("TIE")