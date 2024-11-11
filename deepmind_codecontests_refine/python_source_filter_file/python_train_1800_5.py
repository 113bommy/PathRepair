t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    count = 0
    for j in range(n-1):
        if s[j]==s[j+1]:
            count+=1
    print(count//2)