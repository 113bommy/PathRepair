def b4_ticket_game(n, s):
    l = 0
    r = 0
    for i in range(n):
        if s[i] != '?':
            if i <= n//2:
                l += int(s[i])
                r += int(s[i])
            else:
                l -= int(s[i])
                r -= int(s[i])
        else:
            if i <= n//2:
                r += 9
            else:
                l -= 9
    if l + r == 0:
        return True
    else:
        return False

if __name__ == "__main__":
    n = int(input())
    s = input()
    result = b4_ticket_game(n, s)
    if result:
        print("Bicarp")
    else:
        print("Monocarp")
