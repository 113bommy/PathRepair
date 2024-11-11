def acharstring(s,n):
    for i in range(4):
        if(s[:i+1]+s[n-4+1:n-i] == "2020"):
            print("YES")
            return
            
    print("NO")

for teste in range(int(input())):
    tamanho = int(input())
    string = input()
    acharstring(string, tamanho)
    
