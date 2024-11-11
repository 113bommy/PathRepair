leap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
nonLeap = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
years = nonLeap + leap + nonLeap

if __name__ == "__main__":

    n = int(input())
    days = list(map(int, input().split()))

    for i in range(len(years)):
        if days == years[i:i+n]:
            print("Yes")
            break
    else:
        print("No")