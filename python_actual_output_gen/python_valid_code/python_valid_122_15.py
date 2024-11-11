for _ in range(int(input())):
    n=int(input())
    s=input()
    if n==2 and (int(s[0])==int(s[1]) or int(s[0])<int(s[1])):print("NO")
    else:
        print("YES")
        print(2)
        print(s[:n-1],s[-1])
