def fun(n):
    for i in range(len(n)-7):
        if n[i:i+8]=='0000000' or n[i:i+8]=='1111111':
            return "YES"
    return "NO"
n=str(input())
print(fun(n))