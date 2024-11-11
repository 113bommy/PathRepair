for _ in range(int(input())):
    z = input().split('0')
    z.sort(reverse=True)
    d=0
    for i in range(0,len(z),2):
        d+= len(z[i])
    print(d)