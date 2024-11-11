def acharstring(s,n):
    for i in range(5):
        if(s[:i]+s[n-4+i:] == "2020"):
            print("YES")
            return
            
    print("NO")

for teste in range(int(input())):
    tamanho = int(input())
    string = input()
    acharstring(string, tamanho)
    
