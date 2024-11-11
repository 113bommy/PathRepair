n=int(input())
for i in range(n):
    k=int(input())
    s=input()
    min=0;count=0
    for i in range(len(s)):
        if s[i]=="(":
            count+=1
        else:
            count-=1
        if count<min:
            min=count
    print(min)