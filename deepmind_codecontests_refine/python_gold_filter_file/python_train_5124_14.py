t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    for i in range(n):
        if s[i]=='A':
            break
    print(max(map(len,s[i+1:].split('A'))))