digits = {
    0:6,
    1:2,
    2:5,
    3:5,
    4:4,
    5:5,
    6:6,
    7:3,
    8:7,
    9:6
}

def count(d):
    v = d
    count = 0
    while v!=0:
        count += digits[d%10]
        v = v//10
    return count
def main():
    s,e = [int(v) for v in input().split()]
    total = 0
    for i in range(s, e+1):
        total+=count(i)
    print(total)
if __name__ == "__main__":
    main()
