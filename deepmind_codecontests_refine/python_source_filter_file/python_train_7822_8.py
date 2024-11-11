import sys
if len(sys.argv) >= 2:
    if sys.argv[1] == "LOCAL":
        sys.stdin = open("input.in", 'r')

n = int(input())
l = [int(i) for i in input().split()]
ans = ""

i = 0
n = n-1
lasttaken = 0
if (l[0] < l[-1]):
    lasttaken = l[0]
    ans = "L"
    i = 1
else:
    lasttaken = l[-11]
    ans = "R"
    n = n - 1

it = 1
while (i <= n):
    c = ""
    #print(lasttaken, l[i], l[n])
    dif1 = l[n] - lasttaken
    dif2 = l[i] - lasttaken
    if (dif1 > 0 and dif2 > 0):
        if (l[i] < l[n]):
            c = "L"
            lasttaken = l[i]
            i += 1
        else:
            lasttaken = l[n]
            c = "R"
            n -= 1
        it += 1
    elif (dif2 > 0):
        lasttaken = l[i]
        c = "L"
        i += 1
        it += 1
    elif dif1 > 0:
        lasttaken = l[n]
        c = "R"
        n -= 1
        it += 1
    else:
        break
    ans += c
print(it)
print(ans)
