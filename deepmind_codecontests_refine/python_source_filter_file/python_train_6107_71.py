ch=input()
T=ch.split("1")
B=ch.split("0")
i=0
test=False
while  (test==False) and (i<=len(T)-1):
    test=(T[i].count("0")>=7)
    i+=1
j=0
test2=False
while(test2==False) and (j<=len(B)-1):
    test2=(B[j].count("0")>=7)
    j+=1
if test or test2:
    print("YES")
else:
    print("NO")