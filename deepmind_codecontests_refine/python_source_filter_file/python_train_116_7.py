n = int(input())
s = list(input())


if s == sorted(s): print("NO")
else:
    print("YES")
    for i in range(0,n-1):
        if s[i] < s[i+1]:
            print(i+1 , i+2)
            break


