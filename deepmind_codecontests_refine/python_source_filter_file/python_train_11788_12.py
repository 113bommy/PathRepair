n=int(input())
for _ in range(n):
    s=list(input())
    i=0
    say=0
    el=0
    t=0
    while i<len(s)-2:
        if s[i]=="1" and s[i+1]=="0":
            del s[i+1]
            t=1
            i-=1
            el+=1
        elif t==1:
            t=0
            say+=el
            el=0
        i+=1
    print(say)
