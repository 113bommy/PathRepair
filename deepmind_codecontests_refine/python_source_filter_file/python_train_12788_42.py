A,B,C,D,E,F=map(int, input().split())
ans=[-1,-1]
con=0
for a in range(F//100//A+1):
    for b in range(F//100//B+1):
        for c in range(F//C+1):
            for d in range(F//D+1):
                w = a*A+b*B
                s = c*C+d*D
                if s+w==0: continue
                if 100*w+s>F: break
                if s>E*w: break
                t=s/(s+100*w)
                if con<t:
                    con=t
                    ans[0]=s+100*w
                    ans[1]=s
print(*ans)
