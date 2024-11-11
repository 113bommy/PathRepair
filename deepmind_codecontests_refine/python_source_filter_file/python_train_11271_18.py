for _ in range(int(input())):
    n=int(input())
    s=input()
    c=[]
    for i in range(len(s)):
        if i%2==0:
            c+=s[i]
    print(str(c))