t = int(input())
while t:
    n, a, b = map(int, input().split())
    x = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t","u", "v","w","x", "y", "z"]
    j =0
    s =""
    for i in range(n):
        s = s +x[j]
        j+=1
        if j == 25:
            j=0
    print(s)
    t-=1
