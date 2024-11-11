str=input()
n=int(input())
for i in range(n):
    s=input().split()
    a=int(s[1])
    b=int(s[2])
    if s[0] == 'replace':
        str=str[:a]+s[3]+str[b:]
    elif s[0] == 'reverse':
        str=str[:a]+str[a:b][::-1]+str[b:]
    else:
        print(str[a:b])