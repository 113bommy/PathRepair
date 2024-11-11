
def getArr(s, n):
    Gind = 0
    arr = []
    temp = ""
    temp += s[0]
    for i in range(1, n):
        curr = s[i]
        if curr == s[i - 1]:
            temp += s[i]
        else:
            arr.append((s[i - 1], len(temp)))
            temp = curr
            if s[i-1] == 'G':
                Gind += 1
            i += 1
    if len(temp) > 0:
        arr.append((temp[0], len(temp)))
        if temp[0] == 'G':
            Gind += 1
    return (arr, Gind)


def solve(arr, Gind):
    ans = 0
    hasG = False
    maxG = 0
    for i in range(len(arr)):
        tempMax = 0
        if arr[i][0] == 'S':
            if arr[i][1] > 1:
                le, ri = 0, 0
                if i - 1 >= 0:
                    le = arr[i-1][1]
                elif i + 1 < len(arr):
                    ri = arr[i+1][1]
                tempMax = max(le, ri)
                if Gind > 1:
                    tempMax += 1
                if tempMax > ans:
                    ans = tempMax
            else:
                lef, rig = 0, 0
                if i - 1 >= 0:
                    lef = arr[i-1][1]
                if i + 1 < len(arr):
                    rig = arr[i+1][1]
                tempMax = lef + rig
                if Gind > 2:
                    tempMax += 1
                if tempMax > ans:
                    ans = tempMax
        else:
            hasG = True
            maxG = max(maxG, arr[i][1])

    if ans == 0 and hasG:
        print(maxG)
    else:
        print(ans)



# Main
def run():
    n = int(input())
    s = input()

    arr, gind = getArr(s, n)

    solve(arr, gind)

# end main


# Program Start
if __name__ == "__main__":
    run()