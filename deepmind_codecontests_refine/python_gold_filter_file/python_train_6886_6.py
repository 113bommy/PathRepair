def main():
    k = int(input())
    l = int(input())
    g = k
    i = 0
    while g < int(2**31):
        if g == l:
            return i
        i += 1
        g *= k
    return -1
x = main()
if x >= 0:
    print("YES")
    print(x)
else:
    print("NO")
