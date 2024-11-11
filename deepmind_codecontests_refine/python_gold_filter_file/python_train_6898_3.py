import sys

def inp():
    inp = input().split()
    if len(inp) == 1:
        return int(inp[0])
    else:
        return (int(i) for i in inp)


def inpl():
    inp = input().split()
    for i in range (len(inp)):
        inp[i]=int(inp[i])
    return inp



# Problem 1

# testcases = inp()
#
# for testcase in range (testcases):
#     found=False
#     n=inp()
#     s=inpl()
#     # for i in range (n-2):
#     #     if s[i]+s[i+1]<=s[i+2]:
#     #         print(i+1,i+2,i+3)
#     #         found=True
#     #         break
#     # if not found:
#     #     print(-1)
#     if s[0]+s[1]<=s[-1]:
#         print(1,2,n)
#     else:
#         print(-1)


# Problem 2

testcases = inp()

for testcase in range (testcases):
    s=input().split('0')
    for i in range (len(s)): s[i]=len(s[i])
    s.sort(reverse=True)
    # print(s)
    turn=True
    ans=0
    for i in s:
        if turn:
            ans+=i
        turn=not(turn)
    print(ans)

# Problem 3

# testcases = inp()
#
# for testcase in range (testcases):
#


# Problem 4

# testcases = inp()
#
# for testcase in range (testcases):
#


# Problem 5

# testcases = inp()
#
# for testcase in range (testcases):
#
