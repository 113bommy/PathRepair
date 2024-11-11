import math
for i in range(int(input())):
    n=int(input())
    ra,pb,sc=map(int,input().split())
    s=input()
    al=0
    ans = [""] * n

    for i in range(n):
        mov=s[i]
        if(mov=="R"):
            if(pb>0):
                pb-=1
                al+=1
                ans[i]="P"
        elif mov=="P":
            if(sc>0):
                sc-=1
                al+=1
                ans[i]="S"
            
        elif mov=="S":
            if(ra>0):
                al+=1
                ans[i]="R"
                ra-=1
    if(al<math.ceil(n/2)):
        print("NO")
        continue
    print("YES")
    for i in range(n):
        if ans[i] == "" and ra > 0:
            ans[i] = "R"
            ra -= 1
        elif ans[i] == "" and pb > 0:
            ans[i] = "P"
            pb -= 1
        elif ans[i] == "" and sc > 0:
            ans[i] = "S"
            sc -= 1
    print("".join(ans))
  
                
                