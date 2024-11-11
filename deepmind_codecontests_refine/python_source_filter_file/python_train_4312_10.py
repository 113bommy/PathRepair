
n = int(input())

x = list(map(int, input().split()))


x = [sorted(x[i:i+2]) for i in range(n-1)]


for a,b in x:
    for c,d in x:
        if a < b < c <d:
            print("yes")
            exit()



print("no")

