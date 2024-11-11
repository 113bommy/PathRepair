x=input()
y=input()
s=""
for i in range(len(x)):
    if x[i]==y[i]:
        s=s+"0"
    else:
        s=s+"1"
print(s)