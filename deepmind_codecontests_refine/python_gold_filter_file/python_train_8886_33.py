n=int(input())
s=input()
r,b,g,t=0,0,0,0
if n<1 or n>50:
    print("Bad Entry")
else:
    i=0
    while i<n-1:
        if s[i]=="R" and s[i+1]=="R":
            r+=1
        elif s[i]=="B" and s[i+1]=="B":
            b+=1
        elif s[i]=="G" and s[i+1]=="G":
            g+=1
        i+=1
    t=r+b+g
    print(t)
    