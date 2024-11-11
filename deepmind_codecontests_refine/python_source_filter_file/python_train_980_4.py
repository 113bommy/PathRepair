w = {
 "8<":"[]",
 "[]":"()",
 "()":"8<"
}

a,b = input(), input()
p = 0

for i in range(0, len(a), 2):
    r,s = a[i:i+2],b[i:i+2]
    if(w[r]==s):
        p+=1
    elif(w[s]==r):
        p-=1

if p==0:
    print("TIE")
if p<0:
    print("TEAM 2 WINS")
else:
    print("TEAM 1 WINS")