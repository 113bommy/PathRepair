n,m=map(int,input().split())
s="".join(input()  for __ in range(n))
if m%2==0:
    a=list(("BW"*int(m/2)+"WB"*int(m/2))*int(n/2) if n%2==0 else ("BW"*int(m/2)+"WB"*int(m/2))*int(n/2)+"BW"*int(m/2))
    for j in range(len(s)):
        if s[j]=="-":
            a[j]="-"
    for k in range(0,len(a),m):
        print(*a[k:k+m],sep="")
else:
    a = list(("BW"*int(m/2)+"B"+"WB"*int(m/2)+"W")*int(n/2) if n%2==0 else ("BW"*int(m/2)+"B"+"WB"*int(m/2)+"W")*int(n/2)+"BW"*int(m/2)+"W")
    for j in range(len(s)):
        if s[j] == "-":
            a[j]="-"
    for k in range(0,len(a),m):
        print(*a[k:k+m],sep="")