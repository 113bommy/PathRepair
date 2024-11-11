

t = int(input())
for i in range(t):
    string = input()
    if len(string)%2 == 1:
        print("NO")
        continue

    if string[:int(len(string)/2)] != string[int(len(string)/2)+1:-1]:
        print("NO")
        continue    

    print("YES")
