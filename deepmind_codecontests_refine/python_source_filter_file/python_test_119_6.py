for i in range(int(input())):
    null = input()
    b = [int(x) for x in str(input()).split(" ")]
    if sum(b)%len(b):
        print("0")
    else:
        print("1")
        