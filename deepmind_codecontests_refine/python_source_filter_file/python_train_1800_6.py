for t in range(int(input())):
    n=int(input())
    s=input()
    c=0
    for i in range(n-1):
        if s[i]==s[i+1]:
            c+=1
    print(c//2)