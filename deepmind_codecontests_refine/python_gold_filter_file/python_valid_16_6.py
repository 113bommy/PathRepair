t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    s1=sorted(s)
    k=0
    for i in range(n):
        if s[i]!=s1[i]:
            k+=1
    print(k)