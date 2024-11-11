for _ in range(int(input())):
    n = int(input())
    s = input()
    count = 0
    for i in range(1,n):
        if s[i] != s[0]:
            count+=1
    if count == 0:
        print("-1 -1")
    else:
        for i in range(n-1):
            if s[i] != s[i+1]:
                print(i, i+1)
                break
            