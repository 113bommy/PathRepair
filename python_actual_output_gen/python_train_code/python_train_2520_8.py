s=input()
for i in range(int(input())):
    l=list(input().split())
    l[1]=int(l[1])
    l[2]=int(l[2])+1
    if l[0]=="print":
        print(s[l[1]:l[2]])
    elif l[0]=="reverse":
        s=s[:l[1]]+s[-l[1]:l[2]][::-1]+s[l[2]:]
    elif l[0]=="replace":
        s=s[:l[1]]+l[3]+s[l[2]:]