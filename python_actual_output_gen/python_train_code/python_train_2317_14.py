t=int(input())
while(t!=0):
    s=input()
    p=len(s)
    n=int(s[0])-1
    print((n*4)+(p*(p+1)//2))
    t=t-1