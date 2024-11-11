forbidden = {1: {2, 3, 5, 7}, 2: {23, 37, 53, 73}, 3: {233, 223, 373, 733}, 4: {2333, 2237, 3733, 7333}, 5: {23333, 37337}, 6: []}
def isSubSequence(str1, str2):
    m = len(str1)
    n = len(str2)
    j = 0
    i = 0
    while j < m and i < n:
        if str1[j] == str2[i]:
            j = j+1
        i = i + 1
    return j == m

for _ in range(int(input())):
    n = int(input())
    s = input()
    s = str(s)
    ans = ""
    for k in range(1, 7):
        for i in range(10 ** (k - 1), 10 ** k):
            if (i in forbidden[k]):
                continue
            cand = str(i)
            if ("0" in cand):
                continue;
            if (isSubSequence(cand, s)):
                ans = cand
                break
        if ans != "":
            break;
    print(len(ans))
    print(ans)