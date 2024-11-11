n = int(input())

for i in range(n):
    q = int(input())
    s = input()
    if q == 2 and int(s[0]) > int(s[1]):
        #s = input()
        print("NO")
    else:
        print("YES")
        #s = input()
        print("2" + "\n" + s[0] + " " + s[1:])