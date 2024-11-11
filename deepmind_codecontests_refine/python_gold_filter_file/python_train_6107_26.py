def fun(n):
    for i in range(len(n)-6):
        if n[i:i+7]=='0000000' or n[i:i+7]=='1111111':
            return "YES"
    return "NO"
n=str(input())
print(fun(n))