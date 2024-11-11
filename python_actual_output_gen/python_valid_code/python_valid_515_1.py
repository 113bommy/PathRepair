for _ in range(int(input())):
    s=input()
    t=input()
    print("YES" if(t in s[:i]+s[i::-1] for i in range(len(s))) else "NO")