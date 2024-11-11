str=input()
n=int(input())
for i in range(n):
    s=input().split()
    a=int(s[1])
    b=int(s[2])
    if s[0] == 'replace':
        str=str[:a]+s[3]+str[b+1:]
    elif s[0] == 'reverse':
        str=str[:a]+str[a:b+1][::-1]+str[b+1:]
    else:
        print(str[a:b+1])