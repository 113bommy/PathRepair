def ksusha_the_squirrel(n, k, s):
    trace = 0
    for i in range(n):
        if s[i] == ".":
            if i - trace <= k:
                trace = i
            else:
                return False 
    return True

if __name__ == "__main__":
    [n, k] = map(int, input().split())
    s = input()
    result = ksusha_the_squirrel(n, k, s)
    if result == True:
        print("YES")
    else:
        print("NO")