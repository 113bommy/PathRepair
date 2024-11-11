loops=int(input());
printNo=True;
for i in range(0, loops):
        a = ([str(x) for x in input().split()]);
        prev=int(a[1]);
        nxt=int(a[2]);
        if(prev>=2400 and nxt>prev):
                printNo=False;
if(printNo):
        print("NO");
else:
        print("YES");
