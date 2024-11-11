
for _ in range(int(input())):
    a,b,c,m=map(int,input().split())
    print('Yes' if m<(a+b+c)-3 and m>=2*(max(a,b,c))-a-b-c-1 else 'No')
