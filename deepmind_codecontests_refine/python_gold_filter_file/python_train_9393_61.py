testes = int(input())
for i in range(testes):
    n = int(input())
    if n==1:
        print(-1)
    else:
        string = ""
        for i in range(n-1):
            string+="3"
        string+="4"
        print(string)
