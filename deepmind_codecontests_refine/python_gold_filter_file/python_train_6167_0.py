def solve():
    n=int(input())
    s=input()
    a,b,t="","",1
    for i in s:
        if i=='2' and t:
            a+="1";b+="1"
        elif i=='1' and t:
            a+="1";b+="0";t=0
        else:
            a+="0";b+=i
    print(a,b,sep="\n")
for _ in range(int(input())):
    solve()
