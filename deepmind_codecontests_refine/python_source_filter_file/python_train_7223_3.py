t=int(input())
while t>0:
    s=input().lower()
    if s[0:5]=="miao." and s[-5:]=="lala.":
        print("OMG>.< I don't know!")
    elif s[:5]=="miao.":
        print("Rainbow's")
    elif s[-5:]=="lala.":
        print("Freda's")
        
    else:
        print("OMG>.< I don't know!")
    t-=1