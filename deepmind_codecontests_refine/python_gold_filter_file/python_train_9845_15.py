n=int(input())

if n>=1 and n<=100000:
    s=input()
    if n==len(s):
        c1=0
        c2=0
        
        for x in s:
            if x=='A':
                c1+=1
            elif x=='D':
                c2+=1
            else:
                pass
        if c1>c2:
            print("Anton")
        elif c2>c1:
            print("Danik")
        else:
            print("Friendship")