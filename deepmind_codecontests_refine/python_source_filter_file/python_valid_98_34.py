t=int(input())
while t>0:
    n=int(input())
    s=input()
    for i in range(n-2):
        if s[i]!=s[i+1]:
            print(i+1,i+2)
            break
    else:
        print("-1 -1")
        
    t-=1
