n, m = input().split()
whileloop_count = 1
dotline = 0
k = int(m)-1
print(k)
while whileloop_count <= int(n):
    if whileloop_count % 2 != 0:
        print("#"*int(m))
    elif whileloop_count % 2 == 0 and dotline % 2 == 0:
        print(("."*k+"#"))
        dotline += 1
    elif whileloop_count % 2 == 0 and dotline % 2 != 0:
        print("#"+("."*k))
        dotline += 1
    whileloop_count += 1
