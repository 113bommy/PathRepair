a=str(input())
s=len(a)
for i in range(s):
    if  s<=6:
        print("NO")
        break
    elif s>6 and a[i]==a[i+1]==a[i+2]==a[i+3]==a[i+4]==a[i+5]==a[i+6]:
        print("YES")
        break
    elif a[i]==a[-7]:
        print("NO")
        break
        



    

        
    

   
    