t = int(input())
s = input()
i=0
cout=[]
while i<len(s):
    if s[i]!="o":
        cout.append(s[i])
    else:
        j=i+1
        while j<len(s)-1 and s[j]+s[j+1]=="go":
            j+=2
        if j==0:
            cout.append(s[i])
        else:
            cout.append("***")
        i=j-1
    i+=1
print("".join(cout))