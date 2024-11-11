s=input()
c=0
if 0<=int(s)<=9:
    print(0)
    exit(0)
while True:
    s=str(sum(int(i) for i in s))
    c += 1
    if 0<=int(s)<=9:
        print(c)
        exit(0)