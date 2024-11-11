t = int(input())
for i in range(t):
    ch = input()
    a = ch.count('A')
    b = ch.count('B')
    c = ch.count('C')
    if a == b + c :
        print("YES")
    else:
        print("NO")