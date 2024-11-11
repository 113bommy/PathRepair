t = int(input())

def find_two_idx(s):

    if len(s) == 1:
        return (-1,-1)
    else:
        for idx in range(len(s)-1):
            if s[idx+1] != s[idx]:
                return (idx, idx+1)
        return (-1,-1)



for i in range(t):
    n = int(input())
    s = input()
    print(*find_two_idx(s))
