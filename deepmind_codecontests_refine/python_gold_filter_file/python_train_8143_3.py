p=input();s="";ans=0
for i in range(len(p)) :
    if p[i]=="+" :
        s=s+"1010"
    elif p[i]=="-":
        s=s+"1011"
    elif p[i]==">":
        s=s+"1000"
    elif p[i]=="<":
        s=s+"1001"
    elif p[i]=="[":
        s=s+"1110"
    elif p[i]=="]":
        s=s+"1111"
    elif p[i]==".":
        s=s+"1100"
    elif p[i]==",":
        s=s+"1101"
a=list(s)
a.reverse()
for i in range(len(a)) :
    ans=ans+(int(a[i])*pow(2,i))
print(ans%1000003)
