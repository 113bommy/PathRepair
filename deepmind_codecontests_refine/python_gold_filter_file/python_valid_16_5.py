for _ in range(int(input())):
    n=int(input())
    s=str(input())
    count=0 
    b=sorted(s)
    for i in range(n):
        if s[i]!=b[i]:
            count+=1
    print(count)