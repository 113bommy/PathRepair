t = int(input())

for i in range(t):
    s = input()
    n = len(s)
    if s[0:(n//2)-1]==s[n//2:n-1] and n>1:
        print("YES")
    else:
        print("NO")