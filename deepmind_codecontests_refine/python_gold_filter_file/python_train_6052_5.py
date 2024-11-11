s=input()
i=0
j=0
k=0
while i<len(s):
    if s[i]=='0':
        if j==0:
            print("1 1")
            j=1
        else:
            print("3 1")
            j=0
    else:
        if k==0:
            print("4 3")
            k=1
        else:
            print("4 1")
            k=0
    i+=1
