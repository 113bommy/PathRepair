from random import randint
n, k = map(int, input().split())
MAX_TRIAL = 4500
left, right, mid = 1, n, max(1, n // 2)
inLeft = True
guessing, guess = False, -1
while True:
    if not guessing:
        if inLeft:
            print(left, mid)
        else:
            print(mid, right)
    else:
        print(guess, guess)
    response = input()
    if response == "Yes":
        if guessing or (inLeft and left == mid) or ((not inLeft) and mid == right):
            break
        if inLeft:
            right = min(mid + k, n)
            left = max(left - k, 1)
        else:
            left = max(mid - k, 1)
            right = min(right + k, n)
            inLeft = False
    elif response == "No":
        if guessing:
            left = max(left - k, 1)
            right = min(right + k, n)
        elif inLeft:
            left = max(mid + 1 - k, 1)
            right = min(right + k, n)
            inLeft = False
        else:
            right = min(mid - 1 + k, n)
            left = max(left - k, 1)
    elif response == "Bad":
        break
    mid = (left + right) // 2
    if right - left <= max(4 * k + 4, 1):
        guessing = True
        guess = randint(left, right)
    else:
        guessing = False
    # print("L, M, R, guessing = ", left, mid, right, guessing)
