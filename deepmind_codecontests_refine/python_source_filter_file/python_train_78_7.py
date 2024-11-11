n=int(input())
ans=[]
def rec(i,s):
    if i == n:
        print(s)
        return
    else:
        for j in range(len(set(s)) + 1):
            rec(i+1,s+chr(old("a")+j))
rec(1,"a")